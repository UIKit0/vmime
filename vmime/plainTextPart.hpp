//
// VMime library (http://www.vmime.org)
// Copyright (C) 2002-2013 Vincent Richard <vincent@vmime.org>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// Linking this library statically or dynamically with other modules is making
// a combined work based on this library.  Thus, the terms and conditions of
// the GNU General Public License cover the whole combination.
//

#ifndef VMIME_PLAINTEXTPART_HPP_INCLUDED
#define VMIME_PLAINTEXTPART_HPP_INCLUDED


#include "vmime/textPart.hpp"


namespace vmime
{


/** Text part of type 'text/plain'.
  */

class VMIME_EXPORT plainTextPart : public textPart
{
public:

	plainTextPart();
	~plainTextPart();

	const mediaType getType() const;

	const charset& getCharset() const;
	void setCharset(const charset& ch);

	const shared_ptr <const contentHandler> getText() const;
	void setText(shared_ptr <contentHandler> text);

	size_t getPartCount() const;

	void generateIn(shared_ptr <bodyPart> message, shared_ptr <bodyPart> parent) const;
	void parse(shared_ptr <const bodyPart> message, shared_ptr <const bodyPart> parent, shared_ptr <const bodyPart> textPart);

	bool hasCharset() const;

private:

	shared_ptr <contentHandler> m_text;
	charset m_charset;
	bool m_hasCharset;
};


} // vmime


#endif // VMIME_PLAINTEXTPART_HPP_INCLUDED
