/*
 * UPnP XML helper routines
 */

#ifndef UPNP_XML_H
#define UPNP_XML_H

#include "http.h"

void xml_data_encode(struct wpabuf *buf, const char *data, int len);

void xml_add_tagged_data(struct wpabuf *buf, const char *tag,
                         const char *data);

int xml_next_tag(const char *in, const char **out,
                 const char **out_tagname, const char **end);

char *xml_get_first_item(const char *doc, const char *item);

struct wpabuf *xml_get_base64_item(const char *data, const char *name,
                                   enum http_reply_code *ret);

#endif /* UPNP_XML_H */
