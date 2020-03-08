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

#ifndef INCLUDED_GR_QUANTUM_CONTROLLERS_CALLBACK_MESSAGE_H
#define INCLUDED_GR_QUANTUM_CONTROLLERS_CALLBACK_MESSAGE_H

#include <quantum/api.h>
#include <gnuradio/block.h>


namespace gr {
  namespace quantum {

    /*!
     * \brief callback message
     *
     * \ingroup gates_blk
     *
     * \details
     * input: three messages; output: one message
     *
     */
    class QUANTUM_API controllers_callback_message : virtual public block
    {
    public:
      typedef boost::shared_ptr<controllers_callback_message> sptr;

      static sptr make();
    };
  } /* namespace quantum */
} /* namespace gr */

#endif /* INCLUDED_GR_QUANTUM_CONTROLLERS_CALLBACK_MESSAGE_H */