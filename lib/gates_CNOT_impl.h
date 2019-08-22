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

#ifndef INCLUDED_GR_QUANTUM_GATES_CNOT_IMPL_H
#define INCLUDED_GR_QUANTUM_GATES_CNOT_IMPL_H

#include <quantum/gate.h>
#include <quantum/gates_CNOT.h>

namespace gr {
  namespace quantum {

    class gates_CNOT_impl : public gates_CNOT
    {
    private:
      boost::system_time d_start;
      uint64_t d_total_samples;
/*
      double d_I_freq, d_Q_freq;
      double d_I_amp, d_Q_amp;
      double d_I_bw, d_Q_bw;
      double d_proc_time_ns;
      double d_samps_per_tick, d_samps_per_us;
*/
      bool d_WAVE_port;
      gate *CNOT;

    public:
      gates_CNOT_impl(double I_requency,
                   double Q_requency,
                   double I_amplitude,
                   double Q_amplitude,
                   double I_bandwidth,
                   double Q_bandwidth,
                   double processing_time,
                   double samples_per_sec,
                   bool show_WAVE_port=true);
      ~gates_CNOT_impl();

      // Overloading gr::block::start to reset timer
      bool start();

/*
      void set_I_frequency(double freq);
      double I_frequency();

      void set_Q_frequency(double freq);
      double Q_frequency();

      void set_I_amplitude(double amp);
      double I_amplitude();

      void set_Q_amplitude(double amp);
      double Q_amplitude();

      void set_I_bandwidth(double bw);
      double I_bandwidth();

      void set_Q_bandwidth(double bw);
      double Q_bandwidth();

      void set_processing_time_ns(double proc_time_ns);
      double processing_time();
      void set_sample_rate(double rate);
      double sample_rate() const;
*/

      void set_WAVE_port(bool is_use);
      bool WAVE_port() const;

      void handle_cmd_msg(pmt::pmt_t msg);

      int work(int noutput_items,
               gr_vector_const_void_star &input_items,
               gr_vector_void_star &output_items);
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_GATES_CNOT_IMPL_H */
