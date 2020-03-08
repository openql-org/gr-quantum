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

#ifndef INCLUDED_GR_QUANTUM_CONTROLLERS_SYNC_IMPL_H
#define INCLUDED_GR_QUANTUM_CONTROLLERS_SYNC_IMPL_H

#include <quantum/controllers_sync.h>
#include <boost/timer/timer.hpp>
#include <gnuradio/logger.h>

namespace gr {
  namespace quantum {

    class controllers_sync_impl : public controllers_sync
    {
    private:
      const pmt::pmt_t d_SYNC_out;

      const long WAIT_TIME_NS = 1000000;
      long d_send_time;
      boost::timer::cpu_timer d_proc_timer;

      gr::logger_ptr d_logger;
      gr::logger_ptr d_debug_logger;

    public:
      controllers_sync_impl(
                            );
      ~controllers_sync_impl();

      // Overloading gr::block::start to reset timer
      bool start();

      int work(int noutput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star &output_items);
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_CONTROLLERS_SYNC_IMPL_H */
