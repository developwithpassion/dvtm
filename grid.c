static void
grid(void) {
	unsigned int i, m, nm, n, nx, ny, nw, nh, aw, ah, cols, rows;
	Client *c;

	for(n = 0, m = 0, c = clients; c; c = c->next,n++)
		if(c->minimized)
			m++;
	/* number of non minimized windows */
	nm = n - m;
	/* grid dimensions */
	for(cols = 0; cols <= nm/2; cols++)
		if(cols*cols >= nm)
			break;
	rows = (cols && (cols - 1) * cols >= nm) ? cols - 1 : cols;
	/* window geoms (cell height/width) */
	nh = (wah - m) / (rows ? rows : 1);
	nw = waw / (cols ? cols : 1);
	for(i = 0, c = clients; c; c = c->next,i++) {
		if(!c->minimized){
			/* if there are less clients in the last row than normal adjust the
			 * split rate to fill the empty space */
			if(rows > 1 && i == (rows * cols) - cols && (nm - i) <= (nm % cols))
				nw = waw / (nm - i);
			nx = (i % cols) * nw + wax;
			ny = (i / cols) * nh + way;
			/* adjust height/width of last row/column's windows */
			ah = (i >= cols * (rows -1)) ? wah - m - nh * rows : 0;
			/* special case if there are less clients in the last row */
			if(rows > 1 && i == nm - 1 && (nm - i) < (nm % cols))
				/* (n % cols) == number of clients in the last row */
				aw = waw - nw * (nm % cols);
			else
				aw = ((i + 1) % cols == 0) ? waw - nw * cols : 0;
			if(i % cols){
				mvvline(ny, nx, ACS_VLINE, nh + ah);
				/* if we are on the first row, or on the last one and there are fewer clients
				 * than normal whose border does not match the line above, print a top tree char
				 * otherwise a plus sign. */
				if(i <= cols || (i >= rows * cols - cols && nm % cols && (cols - (nm % cols)) % 2))
					mvaddch(ny, nx, ACS_TTEE);
				else
					mvaddch(ny, nx, ACS_PLUS);
				nx++, aw--;
			}
		} else {
			if(i == nm){ /* first minimized client */
				ny = way + wah - m;
				nx = wax;
				nw = waw;
				nh = 1;
				aw = 0;
				ah = 0;
			} else
				ny++;
		}
		resize(c, nx, ny, nw + aw, nh + ah);
	}
}
