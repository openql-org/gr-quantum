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

#ifndef INCLUDED_GR_QUANTUM_CONTROLLERS_SIMULATOR_IMPL_H
#define INCLUDED_GR_QUANTUM_CONTROLLERS_SIMULATOR_IMPL_H

#include <quantum/gate.h>
#include <quantum/controllers_Simulator.h>

namespace gr {
  namespace quantum {

    class controllers_Simulator_impl : public controllers_Simulator
    {
    private:
      double d_qubit_id;
      boost::system_time d_start;
      uint64_t d_total_samples;
      double d_samps_per_tick, d_samps_per_us;
      double d_center_frequency;
      double d_time_scale_rate;
      bool d_SYNC_port;
      gate *INIT;
      gate *RO;
      gate *X_gate;

    public:
      controllers_Simulator_impl(double qubit_id, double center_RF, double samples_per_sec, double time_scale_rate, bool show_SYNC_port=true);
      ~controllers_Simulator_impl();

      // Overloading gr::block::start to reset timer
      bool start();

      void set_qubit_id(double qubit_id);
      double qubit_id();

      void set_center_frequency(double d_center_RF);
      double center_frequency();

      void set_sample_rate(double rate);
      double sample_rate();

      void set_time_scale_rate(double time_scale_rate);
      double time_scale_rate();

      void set_SYNC_port(bool is_use);
      bool SYNC_port() const;

      void handle_SYNC_msg(pmt::pmt_t msg);

      int work(int noutput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star &output_items);
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_CONTROLLERS_SIMULATOR_IMPL_H */
