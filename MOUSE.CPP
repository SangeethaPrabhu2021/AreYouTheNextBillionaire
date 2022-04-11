//MOUSE DEMONSTRATION PROGRAM
/*INTERUPT      SERVICE   	 PURPOSE
0x33            0x33	  Reset mouse and get status
			  call with: AX = 0X0000
			  Returs:
			  AX = 0XFFFF If mouse support is available
			  AX = 0X0000 If mouse support is not available

0x33 		0x01      Show mouse pointer
			  call with: AX = 0x0001
			  Returns nothing

0x33		0x02	  Hide mouse pointer
			  Call with AX = 0x0002
			  Returns nothing

0x33            0x03      Get mouse position and button status
			  Call with AX = 0x0003
			  Returns: BX = mouse button status
			  Bit significance
			  0  left button is down
			  1  right button is down
			  2  center button is down
			  CX = x coordinate
			  DX = y coordinate

0x33 	       0x04       Set mouse pointer position
			  Call with: AX = 0x0004
			  CX = x coordinate
			  DX = y coordinate
			  Returns nothing

0x33 	      0x07	  Set horizontal limits for pointer
			  Call with: AX = 0x0007
			  CX = minimum  x coordinate
			  DX = maximum x coordinate
			  Returns nothing

0x33	      0x08        Set vertical limits for pointer
			  Call with: AX = 0x0008
			  CX = minimum  y coordinate
			  DX = maximum y coordinate
			  Returns nothing*/



//Declaration for  i/o Registers
 union REGS o,i ;


// INITIALISES MOUSE
interrupt initmouse()
 {
  i.x.ax = 0 ;
  int86(0x33, &i, &o) ;
  return ( o.x.ax == 0 ? -1:0 ) ;

 }


 //DISPLAY MOUSE POINTER
  showmouseptr()
  {
    i.x.ax = 1 ;
    int86( 0x33, &i, &o );
  } //RESTRICTS MOUSE POINTER
     restrictmouseptr(int x1, int y1, int x2, int y2 )
     {    //X - AXIS limits
     i.x.ax = 7 ;
     i.x.cx = x1 ;
     i.x.dx = x2 ;
     int86(0x33, &i, &o ) ;

      //Y - AXIS limits
     i.x.ax = 8 ;
     i.x.cx = y1 ;
     i.x.dx = y2 ;
     int86(0x33, &i, &o) ;

   }
  //GETS MOUSE COORDINATES AND BUTTON STATUS

  getmousepos(int *button, int *x, int *y )
  {
   i.x.ax = 3 ;
   int86(0x33, &i, &o ) ;

   *button = o.x.bx ;
   *x = o.x.cx ;
   *y = o.x.dx ;
  }









