/* -*- c++ -*- */
/*
 * Copyright 2013 Airbus DS CyberSecurity.
 * Authors: Jean-Michel Picod, Arnaud Lebrun, Jonathan Christofer Demay
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ZWAVE_PREAMBLE_IMPL_H
#define INCLUDED_ZWAVE_PREAMBLE_IMPL_H

#include <Zwave/preamble.h>

namespace gr {
  namespace Zwave {

struct beam{
	unsigned char preamble[20];
	unsigned char sof;
	unsigned char beam_hdr;
	unsigned char nodeid;

	beam(char node){
		std::memset (this->preamble, 0x55, 20);
		sof = 0xF0;		
		beam_hdr = 0x55;
		nodeid = node;
	}

	beam(){
		std::memset (this->preamble, 0x55, 20);
		sof = 0xF0;
		beam_hdr = 0x55;
		nodeid = 0xFF; //Broadcast
	}
}__attribute__((packed));

    class preamble_impl : public preamble
    {
     private:
      // Nothing to declare in this block.
        //enought for a trame
        char preamble[256];

     public:
      preamble_impl(int preamble_length); // Added param for EZ-Wave
      ~preamble_impl();


      void general_work(pmt::pmt_t msg);
			void set_preamble(int  preamble_length); // For EZ-Wave
    };

  } // namespace Zwave
} // namespace gr

#endif /* INCLUDED_ZWAVE_PREAMBLE_IMPL_H */
