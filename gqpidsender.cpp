/*
 * Copyright (c) 2011 Kushal Das <kdas@redhat.com>
 *
 * Licesed under MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include <glib.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Session.h>
#include <gqpidsender.h>
#include <gqpidmessage.h>

using namespace qpid::messaging;

struct _GQpidSender
{
    Sender sender;

    _GQpidSender(Session &s, const gchar *add)
    {
        sender = s.createSender (add);
    }
};

GQpidSender*
g_qpid_sender_new (Session &s, const gchar *add)
{
    GQpidSender *sender;
    sender = new GQpidSender (s, add);

    return sender;
}

/**
 * g_qpid_sender_send:
 * @sender: a #GQpidSender* object
 * @msg: a #GQpidMessage object which to be send
 *
 * It sends the message.
 **/
void
g_qpid_sender_send (GQpidSender *sender,
                    GQpidMessage  *msg)
{
    g_return_if_fail (msg != NULL);

    g_qpid_message_send (msg, sender->sender);
}


