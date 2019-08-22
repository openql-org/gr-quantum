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

#ifndef INCLUDED_GR_QUANTUM_CONTROLLERS_COPROSESSOR_IMPL_H
#define INCLUDED_GR_QUANTUM_CONTROLLERS_COPROSESSOR_IMPL_H

#include <quantum/gate.h>
#include <quantum/controllers_Coprocessor.h>

namespace gr {
  namespace quantum {

    class controllers_Coprocessor_impl : public controllers_Coprocessor
    {
    private:
      double d_qubit_id;
      boost::system_time d_start;
      uint64_t d_total_samples;
      double d_samps_per_tick, d_samps_per_us;
      double d_time_scale_rate;
      bool d_SYNC_port;
      gate *INIT;
      gate *RO;
      gate *X_gate;
      gate *Y_gate;
      gate *Z_gate;
      gate *H_gate;
      gate *T_gate;
      gate *S_gate;

    public:
      controllers_Coprocessor_impl(double qubit_id, double samples_per_sec, double time_scale_rate, bool show_SYNC_port=true);
      ~controllers_Coprocessor_impl();

      // Overloading gr::block::start to reset timer
      bool start();

      void set_qubit_id(double qubit_id);
      double qubit_id();

      void set_sample_rate(double rate);
      double sample_rate();

      void set_time_scale_rate(double time_scale_rate);
      double time_scale_rate();

      void set_INIT_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);
      void set_RO_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);

      void set_X_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);
      void set_Y_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);
      void set_Z_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);
      void set_H_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);
      void set_T_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);
      void set_S_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec);

      void set_SYNC_port(bool is_use);
      bool SYNC_port() const;

      void handle_cmd_msg(pmt::pmt_t msg);
      void handle_SYNC_msg(pmt::pmt_t msg);

      int work(int noutput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star &output_items);
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_CONTROLLER_COPROSESSORS_IMPL_H */
