/*

 printoled.ino
 
 Universal 8bit Graphics Library, http://code.google.com/p/u8glib/ 
 Copyright (c) 2012, olikraus@gmail.com
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, 
 are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this list 
 of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright notice, this 
 list of conditions and the following disclaimer in the documentation and/or other 
 materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
 CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
 STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
 
 */

#include "U8glib.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NO_ACK);	// Display which does not send ACK

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_9x15B);
  //  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 11, "Hello Doug!");
  u8g.drawStr( 0, 24, "Happy happy");
  u8g.drawStr( 0, 37, "Line 3");
  u8g.drawStr( 0, 50, "Line 4");
  u8g.setPrintPos(0, 63);
}

void setup(void) 
{
  u8g.setColorIndex(1);  // default color
}

int x = 0;

void loop(void) 
{
  u8g.setPrintPos(0, 63);
  u8g.print("BWww");
  // picture loop
  u8g.firstPage();  
  do {
    u8g.setPrintPos(0, 63);
    u8g.print(x);
    x++;
    draw();
  } 
  while( u8g.nextPage() );

  // rebuild the picture after some delay
  delay(50);
}


