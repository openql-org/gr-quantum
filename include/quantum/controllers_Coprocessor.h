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

#ifndef INCLUDED_GR_QUANTUM_CONTROLLERS_COPROSESSOR_H
#define INCLUDED_GR_QUANTUM_CONTROLLERS_COPROSESSOR_H

#include <quantum/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace quantum {

    /*!
     * \brief Quantum Coprocessor for OpenQL compiler's binary.
     *
     * \ingroup controller_blk
     *
     * \details
     * input: one messages; output: two streams of float
     *
     */
    class QUANTUM_API controllers_Coprocessor : virtual public sync_block
    {
    public:
      typedef boost::shared_ptr<controllers_Coprocessor> sptr;

      static sptr make(double qubit_id, double samples_per_sec, double time_scale_rate, bool show_SYNC_port=true);

      //! Sets Qubit ID number.
      virtual void set_qubit_id(double qubit_id) = 0;

      //! Gets Qubit ID number.
      virtual double qubit_id() = 0;

      //! Sets the sample rate in samples per second.
      virtual void set_sample_rate(double rate) = 0;

      //! Get the sample rate in samples per second.
      virtual double sample_rate() = 0;

      //! Sets Time scale rate.
      virtual void set_time_scale_rate(double time_scale_rate) = 0;

      //! Get Time scale rate.
      virtual double time_scale_rate() = 0;

      virtual void set_INIT_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      virtual void set_RO_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      virtual void set_X_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      virtual void set_Y_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      virtual void set_Z_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      virtual void set_H_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      virtual void set_T_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      virtual void set_S_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) = 0;

      //! Sets using SYNC in/out.
      virtual void set_SYNC_port(bool is_use) = 0;

      //! Get using SYNC in/out.
      virtual bool SYNC_port() const = 0;

    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_CONTROLLERS_COPROSESSOR_H */