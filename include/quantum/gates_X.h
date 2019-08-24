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

#ifndef INCLUDED_GR_QUANTUM_GATES_X_H
#define INCLUDED_GR_QUANTUM_GATES_X_H

#include <quantum/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace quantum {

    /*!
     * \brief X gate
     *
     * \ingroup gates_blk
     *
     * \details
     * input: one messages; output: one message
     *
     */
    class QUANTUM_API gates_X : virtual public sync_block
    {
    public:
      typedef boost::shared_ptr<gates_X> sptr;

      static sptr make(double frequency,
                       double I_amplitude,
                       double Q_amplitude,
                       double I_bandwidth,
                       double Q_bandwidth,
                       double processing_time,
                       double samples_per_sec,
                       bool show_WAVE_port=true);

/*
      //! Sets I frequecy..
      virtual void set_I_frequency(double freq) = 0;
      
      //! Get I frequecy..
      virtual double I_frequency() = 0;

      //! Sets Q frequecy..
      virtual void set_Q_frequency(double freq) = 0;

      //! Get Q frequecy..
      virtual double Q_frequency() = 0;

      //! Sets I amplitude..
      virtual void set_I_amplitude(double amp) = 0;

      //! Get I amplitude..
      virtual double I_amplitude() = 0;

      //! Sets Q amplitude..
      virtual void set_Q_amplitude(double amp) = 0;

      //! Get Q amplitude..
      virtual double Q_amplitude() = 0;

      //! Sets I bandwidth..
      virtual void set_I_bandwidth(double bw) = 0;

      //! Get I bandwidth..
      virtual double I_bandwidth() = 0;

      //! Sets Q bandwidth..
      virtual void set_Q_bandwidth(double bw) = 0;

      //! Get Q bandwidth..
      virtual double Q_bandwidth() = 0;


      //! Sets processing time(ns)..
      virtual void set_processing_time_ns(double proc_time_ns) = 0;

      //! Get processing time(ns)..
      virtual double processing_time() = 0;

      //! Sets the sample rate in samples per second.
      virtual void set_sample_rate(double rate) = 0;

      //! Get the sample rate in samples per second.
      virtual double sample_rate() const = 0;

*/

      //! Sets using WAVE out.
      virtual void set_WAVE_port(bool is_use) = 0;

      //! Get using WAVE out.
      virtual bool WAVE_port() const = 0;
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_GATES_X_H */
