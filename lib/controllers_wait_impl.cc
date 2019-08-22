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

#include "controllers_wait_impl.h"
#include <gnuradio/io_signature.h>
#include <cstring>
#include <boost/thread/thread.hpp>
#include <limits>

namespace gr {
  namespace quantum {

    controllers_wait::sptr
    controllers_wait::make(
                  double wait_time)

    {
      return gnuradio::get_initial_sptr
        (new controllers_wait_impl(
                          wait_time));
    }

    controllers_wait_impl::controllers_wait_impl(
                                 double wait_time)
      : sync_block("controllers_wait",
                      io_signature::make(0, 0, 0),
                      io_signature::make(0, 0, 0))
    {
      set_wait_time_ns(wait_time);

      message_port_register_out(message_ports_out());
      message_port_register_in(pmt::mp("in"));
      set_msg_handler(pmt::mp("in"), boost::bind(&controllers_wait_impl::handle_cmd_msg, this, _1));
    }

    controllers_wait_impl::~controllers_wait_impl()
    {
    }

    bool
    controllers_wait_impl::start()
    {
      d_start = boost::get_system_time();
      return block::start();
    }

    void
    controllers_wait_impl::handle_cmd_msg(pmt::pmt_t msg)
    {
      // add the field and publish
      pmt::pmt_t meta = pmt::car(msg);
      if(pmt::is_null(meta)){
        meta = pmt::make_dict();
        } else if(!pmt::is_dict(meta)){
        throw std::runtime_error("cmd received non cmd input");
        }
//TODO      meta = pmt::dict_add(meta, "k", "v");
      this->_post(message_ports_out(), pmt::cons(meta, pmt::cdr(msg)));
//      message_port_pub(message_ports_out(), pmt::cons(meta, pmt::cdr(msg)));
    }



    void
    controllers_wait_impl::set_wait_time_ns(double wait_time_ns)
    {
      d_wait_time_ns = wait_time_ns;
    }
    double
    controllers_wait_impl::wait_time() const
    {
      return d_wait_time_ns;
    }



    int
    controllers_wait_impl::work(int noutput_items,
                        gr_vector_const_void_star &input_items,
                        gr_vector_void_star &output_items)
    {
      return noutput_items;
    }

  } /* namespace quantum */
} /* namespace gr */
