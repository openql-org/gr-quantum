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

#include <quantum/gate.h>
#include <cstring>
#include <limits>

namespace gr {
  namespace quantum {

    gate::gate(  double I_requency,
                                 double Q_requency,
                                 double I_amplitude,
                                 double Q_amplitude,
                                 double I_bandwidth,
                                 double Q_bandwidth,
                                 double processing_time
,                                double samples_per_sec)
    {
      set_I_frequency(I_requency);
      set_Q_frequency(Q_requency);
      set_I_amplitude(I_amplitude);
      set_Q_amplitude(Q_amplitude);
      set_I_bandwidth(I_bandwidth);
      set_Q_bandwidth(Q_bandwidth);
      set_processing_time_ns(processing_time);
      set_sample_rate(samples_per_sec);
    }

    gate::~gate()
    {
    }


    void
    gate::set_I_frequency(double freq)
    {
      d_I_freq = freq;
    }
    double
    gate::I_frequency() {
      return d_I_freq;
    }

    void
    gate::set_Q_frequency(double freq)
    {
      d_Q_freq = freq;
    }
    double
    gate::Q_frequency()
    {
      return d_Q_freq;
    }

    void
    gate::set_I_amplitude(double amp)
    {
      d_I_amp = amp;
    }
    double
    gate::I_amplitude()
    {
      return d_I_amp;
    }

    void
    gate::set_Q_amplitude(double amp)
    {
      d_Q_amp = amp;
    }
    double
    gate::Q_amplitude()
    {
      return d_Q_amp;
    }

    void
    gate::set_I_bandwidth(double bw)
    {
      d_I_bw = bw;
    }
    double
    gate::I_bandwidth()
    {
      return d_I_bw;
    }

    void
    gate::set_Q_bandwidth(double bw)
    {
      d_Q_bw = bw;
    }
    double
    gate::Q_bandwidth()
    {
      return d_Q_bw;
    }


    void
    gate::set_processing_time_ns(double proc_time_ns)
    {
      d_proc_time_ns = proc_time_ns;
    }
    double
    gate::processing_time()
    {
      return d_proc_time_ns;
    }


    void
    gate::set_sample_rate(double rate)
    {
      //changing the sample rate performs a reset of state params
      d_start = boost::get_system_time();
      d_total_samples = 0;
      d_samps_per_tick = rate/boost::posix_time::time_duration::ticks_per_second();
      d_samps_per_us = rate/1e6;
    }

    double
    gate::sample_rate() const
    {
      return d_samps_per_us * 1e6;
    }

  } /* namespace quantum */
} /* namespace gr */
