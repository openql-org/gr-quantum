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

#ifndef INCLUDED_GR_QUANTUM_GATES_JUNCTION_IMPL_H
#define INCLUDED_GR_QUANTUM_GATES_JUNCTION_IMPL_H

#include <quantum/gate.h>
#include <quantum/gates_junction.h>

namespace gr {
  namespace quantum {

    class gates_junction_impl : public gates_junction
    {
    private:
      boost::system_time d_start;
      double d_wait_time_ns;

    public:
      gates_junction_impl(
                   double wait_time);
      ~gates_junction_impl();

      // Overloading gr::block::start to reset timer
      bool start();

      void set_wait_time_ns(double wait_time_ns);
      double wait_time() const;

      void handle_cmd_msg(pmt::pmt_t msg);
      void handle_NOT_msg(pmt::pmt_t msg);

      int work(int noutput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star &output_items);
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_GATES_JUNCTION_IMPL_H */
