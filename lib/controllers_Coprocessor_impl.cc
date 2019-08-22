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

#include "controllers_Coprocessor_impl.h"
#include <gnuradio/io_signature.h>
#include <cstring>
#include <boost/thread/thread.hpp>
#include <limits>

namespace gr {
  namespace quantum {

    controllers_Coprocessor::sptr
    controllers_Coprocessor::make(double qubit_id, double samples_per_sec, double time_scale_rate, bool show_SYNC_port)
    {
      return gnuradio::get_initial_sptr
        (new controllers_Coprocessor_impl(qubit_id, samples_per_sec, time_scale_rate, show_SYNC_port));
    }

    controllers_Coprocessor_impl::controllers_Coprocessor_impl(double qubit_id, double samples_per_sec, double time_scale_rate, bool show_SYNC_port)
      : sync_block("controllers_Coprocessor",
                      io_signature::make(0, 0, 0),
                      io_signature::make(1, 1, sizeof(gr_complex)))
    {
      set_qubit_id(qubit_id);
      set_sample_rate(samples_per_sec);
      set_time_scale_rate(time_scale_rate);
      set_SYNC_port(show_SYNC_port);


      message_port_register_in(pmt::mp("in"));
      set_msg_handler(pmt::mp("in"), boost::bind(&controllers_Coprocessor_impl::handle_cmd_msg, this, _1));

      message_port_register_out(message_ports_out());
      message_port_register_in(pmt::mp("sync_in"));
      set_msg_handler(pmt::mp("sync_in"), boost::bind(&controllers_Coprocessor_impl::handle_SYNC_msg, this, _1));

    }

    controllers_Coprocessor_impl::~controllers_Coprocessor_impl()
    {
    }

    bool
    controllers_Coprocessor_impl::start()
    {
      d_start = boost::get_system_time();
      d_total_samples = 0;
      return block::start();
    }

    void
    controllers_Coprocessor_impl::handle_cmd_msg(pmt::pmt_t msg) {
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

    void
    controllers_Coprocessor_impl::set_qubit_id(double qubit_id)
    {
      d_qubit_id = qubit_id;
    }
    double
    controllers_Coprocessor_impl::qubit_id()
    {
      return d_qubit_id;
    }

    void
    controllers_Coprocessor_impl::set_sample_rate(double rate)
    {
      //changing the sample rate performs a reset of state params
      d_start = boost::get_system_time();
      d_total_samples = 0;
      d_samps_per_tick = rate/boost::posix_time::time_duration::ticks_per_second();
      d_samps_per_us = rate/1e6;
    }

    double
    controllers_Coprocessor_impl::sample_rate()
    {
      return d_samps_per_us * 1e6;
    }

    void
    controllers_Coprocessor_impl::set_time_scale_rate(double rate)
    {
      d_time_scale_rate = rate;
    }

    double
    controllers_Coprocessor_impl::time_scale_rate()
    {
      return d_time_scale_rate;
    }

    void
    controllers_Coprocessor_impl::set_SYNC_port(bool is_use) {
        d_SYNC_port = !is_use;
    }

    bool
    controllers_Coprocessor_impl::SYNC_port() const{
      return d_SYNC_port;
    }

    void
    controllers_Coprocessor_impl::handle_SYNC_msg(pmt::pmt_t msg)
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

    void
    controllers_Coprocessor_impl::set_INIT_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      INIT = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }
    void
    controllers_Coprocessor_impl::set_RO_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      RO = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }

    void
    controllers_Coprocessor_impl::set_X_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      X_gate = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }
    void
    controllers_Coprocessor_impl::set_Y_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      Y_gate = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }
    void
    controllers_Coprocessor_impl::set_Z_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      Z_gate = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }
    void
    controllers_Coprocessor_impl::set_H_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      H_gate = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }
    void
    controllers_Coprocessor_impl::set_T_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      T_gate = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }
    void
    controllers_Coprocessor_impl::set_S_gete_parameters(double I_requency, double Q_requency, double I_amplitude, double Q_amplitude, double I_bandwidth, double Q_bandwidth, double processing_time, double samples_per_sec) {
      S_gate = new gate(I_requency, Q_requency, I_amplitude, Q_amplitude, I_bandwidth, Q_bandwidth, processing_time, samples_per_sec);
    }


    int
    controllers_Coprocessor_impl::work(int noutput_items,
                        gr_vector_const_void_star &input_items,
                        gr_vector_void_star &output_items)
    {
      return noutput_items;
    }

  } /* namespace quantum */
} /* namespace gr */
