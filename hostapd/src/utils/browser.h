/*
 * Hotspot 2.0 client - Web browser
 */

#ifndef BROWSER_H
#define BROWSER_H

#ifdef CONFIG_NO_BROWSER
static inline int hs20_web_browser(const char *url, int ignore_tls)
{
    return -1;
}
#else /* CONFIG_NO_BROWSER */

int hs20_web_browser(const char *url, int ignore_tls);

#endif /* CONFIG_NO_BROWSER */

#endif /* BROWSER_H */
