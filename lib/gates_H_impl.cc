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

#include "gates_H_impl.h"
#include <gnuradio/io_signature.h>
#include <cstring>
#include <boost/thread/thread.hpp>
#include <limits>

namespace gr {
  namespace quantum {

    gates_H::sptr
    gates_H::make(double frequency,
                  double I_amplitude,
                  double Q_amplitude,
                  double I_bandwidth,
                  double Q_bandwidth,
                  double processing_time,
                  double samples_per_sec,
                  bool show_WAVE_port)

    {
      return gnuradio::get_initial_sptr
        (new gates_H_impl(frequency,
                          I_amplitude,
                          Q_amplitude,
                          I_bandwidth,
                          Q_bandwidth,
                          processing_time,
                          samples_per_sec,
                          show_WAVE_port));
    }

    gates_H_impl::gates_H_impl(  double frequency,
                                 double I_amplitude,
                                 double Q_amplitude,
                                 double I_bandwidth,
                                 double Q_bandwidth,
                                 double processing_time, 
                                 double samples_per_second,
                                 bool show_WAVE_port)
      : sync_block("gates_H",
                      io_signature::make(0, 0, 0),
                      io_signature::make(2, 2, sizeof(float)))
    {
/*
      set_I_frequency(I_requency);
      set_Q_frequency(Q_requency);
      set_I_amplitude(I_amplitude);
      set_Q_amplitude(Q_amplitude);
      set_I_bandwidth(I_bandwidth);
      set_Q_bandwidth(Q_bandwidth);
      set_processing_time_ns(processing_time);
      set_sample_rate(samples_per_second);
*/
      d_gate = new gate(frequency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_second);
      set_WAVE_port(show_WAVE_port);


      message_port_register_out(message_ports_out());
      message_port_register_in(pmt::mp("in"));
      set_msg_handler(pmt::mp("in"), boost::bind(&gates_H_impl::handle_cmd_msg, this, _1));
    }

    gates_H_impl::~gates_H_impl()
    {
    }

    bool
    gates_H_impl::start()
    {
      d_start = boost::get_system_time();
      d_total_samples = 0;
      return block::start();
    }

    void
    gates_H_impl::handle_cmd_msg(pmt::pmt_t msg)
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


/*
    void
    gates_H_impl::set_I_frequency(double freq) {
      d_I_freq = freq;
    }
    double
    gates_H_impl::I_frequency() {
      return d_I_freq;
    }

    void
    gates_H_impl::set_Q_frequency(double freq);
      d_Q_freq = freq;
    }
    double
    gates_H_impl::Q_frequency();
      return d_Q_freq;
    }

    void
    gates_H_impl::set_I_amplitude(double amp);
      d_I_amp = amp;
    }
    double
    gates_H_impl::I_amplitude();
      return d_I_amp;
    }

    void
    gates_H_impl::set_Q_amplitude(double amp);
      d_Q_amp = amp;
    }
    double
    gates_H_impl::Q_amplitude();
      return d_Q_amp;
    }

    void
    gates_H_impl::set_I_bandwidth(double bw);
      d_I_bw = bw;
    }
    double
    gates_H_impl::I_bandwidth();
      return d_I_bw;
    }

    void
    gates_H_impl::set_Q_bandwidth(double bw);
      d_Q_bw = bw;
    }
    double
    gates_H_impl::Q_bandwidth();
      return d_Q_bw;
    }


    void
    gates_H_impl::set_processing_time_ns(double proc_time_ns);
      d_proc_time_ns = proc_time_ns;
    }
    double
    gates_H_impl::processing_time();
      return d_proc_time_ns;
    }


    void
    gates_H_impl::set_sample_rate(double rate)
    {
      //changing the sample rate performs a reset of state params
      d_start = boost::get_system_time();
      d_total_samples = 0;
      d_samps_per_tick = rate/boost::posix_time::time_duration::ticks_per_second();
      d_samps_per_us = rate/1e6;
    }

    double
    gates_H_impl::sample_rate() const
    {
      return d_samps_per_us * 1e6;
    }

*/

    void
    gates_H_impl::set_WAVE_port(bool is_use) {
        d_WAVE_port = !is_use;
    }

    bool
    gates_H_impl::WAVE_port() const{
      return d_WAVE_port;
    }



    int
    gates_H_impl::work(int noutput_items,
                        gr_vector_const_void_star &input_items,
                        gr_vector_void_star &output_items)
    {
      return noutput_items;
    }

  } /* namespace quantum */
} /* namespace gr */
