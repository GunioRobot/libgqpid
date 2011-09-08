#include <glib.h>

#ifdef __cplusplus
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Message.h>
#endif

typedef struct _GQpidMessage GQpidMessage;
#ifdef __cplusplus
void                            g_qpid_message_send             (GQpidMessage *, qpid::messaging::Sender&);
GQpidMessage*                   g_qpid_message_new_from_msg     (qpid::messaging::Message&);
void                            g_qpid_message_release_session   (GQpidMessage *, qpid::messaging::Session&);
void                            g_qpid_message_reject_session   (GQpidMessage *, qpid::messaging::Session&);
extern "C" {
#endif
GQpidMessage*                   g_qpid_message_new              (gchar*);
const gchar*                    g_qpid_message_get_content      (GQpidMessage *);
#ifdef __cplusplus
}
#endif
