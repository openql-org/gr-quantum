/* -*- c++ -*- */
/*
 * Copyright (c) 2006-2019 SIProp.org Noritsuna Imamura(noritsuna@siprop.org)
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "measurements_Detector_impl.h"
#include <gnuradio/io_signature.h>
#include <cstring>
#include <boost/thread/thread.hpp>
#include <limits>

namespace gr {
  namespace quantum {

    measurements_Detector::sptr
    measurements_Detector::make(
                           )

    {
      return gnuradio::get_initial_sptr
        (new measurements_Detector_impl(
                                   ));
    }

    measurements_Detector_impl::measurements_Detector_impl(
                                                 )
      : sync_block("measurements_Detector",
                      io_signature::make(1, -1, sizeof(gr_complex)),
                      io_signature::make(1, 1, sizeof(gr_complex)))
    {

      message_port_register_out(message_ports_out());
    }

    measurements_Detector_impl::~measurements_Detector_impl()
    {
    }

    bool
    measurements_Detector_impl::start()
    {
      return block::start();
    }


    int
    measurements_Detector_impl::work(int noutput_items,
                        gr_vector_const_void_star &input_items,
                        gr_vector_void_star &output_items)
    {
      return noutput_items;
    }

  } /* namespace quantum */
} /* namespace gr */
