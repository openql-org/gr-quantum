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

#ifndef INCLUDED_GR_QUANTUM_GATE_H
#define INCLUDED_GR_QUANTUM_GATE_H

#include <gnuradio/api.h>
#include <gnuradio/runtime_types.h>
#include <gnuradio/io_signature.h>
#include <gnuradio/thread/thread.h>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/foreach.hpp>
#include <boost/thread/condition_variable.hpp>
#include <quantum/api.h>

namespace gr {
  namespace quantum {

    /*!
     * \brief gate class
     *
     * \ingroup gates_blk
     *
     * \details
     *
     */
    class gate
    {
    private:
      double d_freq;
      double d_I_amp, d_Q_amp;
      double d_I_bw, d_Q_bw;
      double d_proc_time_ns;
      boost::system_time d_start;
      uint64_t d_total_samples;
      double d_samps_per_tick, d_samps_per_us;

    public:
      gate(double frequency,
           double I_amplitude,
           double Q_amplitude,
           double I_bandwidth,
           double Q_bandwidth,
           double processing_time,
           double samples_per_sec);
      ~gate();

      void set_frequency(double freq);
      double frequency();

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
      
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_GATE_H */
