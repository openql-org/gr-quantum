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

#ifndef INCLUDED_GR_QUANTUM_MEASUREMENTS_BLOCH_IMPL_H
#define INCLUDED_GR_QUANTUM_MEASUREMENTS_BLOCH_IMPL_H

#include <quantum/measurements_Bloch.h>
#include <gnuradio/high_res_timer.h>
#include <gnuradio/qtgui/constellationdisplayform.h>

namespace gr {
  namespace quantum {

    class QUANTUM_API measurements_Bloch_impl : public measurements_Bloch
    {
    private:
      void initialize();

      int d_size, d_buffer_size;
      std::string d_name;
      int d_nconnections;

      int d_index, d_start, d_end;
      std::vector<double*> d_residbufs_real;
      std::vector<double*> d_residbufs_imag;

      int d_argc;
      char *d_argv;
      QWidget *d_parent;
      ConstellationDisplayForm *d_main_gui;

      gr::high_res_timer_type d_update_time;
      gr::high_res_timer_type d_last_time;

      // Members used for triggering scope
      trigger_mode d_trigger_mode;
      trigger_slope d_trigger_slope;
      float d_trigger_level;
      int d_trigger_channel;
      pmt::pmt_t d_trigger_tag_key;
      bool d_triggered;
      int d_trigger_count;

      void _reset();
      void _npoints_resize();
      void _gui_update_trigger();
      void _test_trigger_tags(int nitems);
      void _test_trigger_norm(int nitems, gr_vector_const_void_star inputs);
      bool _test_trigger_slope(const gr_complex *in) const;

      // Handles message input port for displaying PDU samples.
      void handle_pdus(pmt::pmt_t msg);

    public:
      measurements_Bloch_impl(int size,
			const std::string &name,
			int nconnections,
			QWidget *parent=NULL);
      ~measurements_Bloch_impl();

      bool check_topology(int ninputs, int noutputs);

      void exec_();
      QWidget*  qwidget();

#ifdef ENABLE_PYTHON
      PyObject* pyqwidget();
#else
      void* pyqwidget();
#endif

      void set_y_axis(double min, double max);
      void set_x_axis(double min, double max);

      void set_update_time(double t);
      void set_title(const std::string &title);
      void set_line_label(int which, const std::string &label);
      void set_line_color(int which, const std::string &color);
      void set_line_width(int which, int width);
      void set_line_style(int which, int style);
      void set_line_marker(int which, int marker);
      void set_nsamps(const int size);
      void set_line_alpha(int which, double alpha);
      void set_trigger_mode(trigger_mode mode, trigger_slope slope,
                            float level, int channel,
                            const std::string &tag_key="");

      std::string title();
      std::string line_label(int which);
      std::string line_color(int which);
      int line_width(int which);
      int line_style(int which);
      int line_marker(int which);
      double line_alpha(int which);

      void set_size(int width, int height);

      int nsamps() const;
      void enable_menu(bool en);
      void enable_autoscale(bool en);
      void enable_grid(bool en);
      void enable_axis_labels(bool en);
      void disable_legend();
      void reset();

      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_MEASUREMENTS_BLOCH_IMPL_H */