/*****************************************************************************
 *  $Id: gtkcompletionline.h,v 1.7 2001/07/02 09:12:16 mishoo Exp $
 *  Copyright (C) 2000, Mishoo
 *  Author: Mihai Bazon                  Email: mishoo@fenrir.infoiasi.ro
 *
 *   Distributed under the terms of the GNU General Public License. You are
 *  free to use/modify/distribute this program as long as you comply to the
 *    terms of the GNU General Public License, version 2 or above, at your
 *      option, and provided that this copyright notice remains intact.
 *****************************************************************************/


#ifndef __GTKCOMPLETIONLINE_H__
#define __GTKCOMPLETIONLINE_H__

#include <gtk/gtkentry.h>

#include <string>

#include "history.h"

extern "C++" {

#define GTK_COMPLETION_LINE(obj) \
  GTK_CHECK_CAST(obj, gtk_completion_line_get_type(), GtkCompletionLine)
#define GTK_COMPLETION_LINE_CLASS(klass) \
  GTK_CHECK_CLASS_CAST(klass, gtk_completion_line_get_type(), GtkCompletionLineClass)
#define IS_GTK_COMPLETION_LINE(obj) \
  GTK_CHECK_TYPE(obj, gtk_completion_line_get_type())

  typedef struct _GtkCompletionLine GtkCompletionLine;
  typedef struct _GtkCompletionLineClass GtkCompletionLineClass;

  struct _GtkCompletionLine
  {
	GtkEntry parent;
    GtkWidget *win_compl;
    GtkWidget *list_compl;
    int list_compl_items_where;
    int list_compl_nr_rows;
    int pos_in_text;
    
    GList *cmpl;
    GList *where;

    HistoryFile *hist;
    bool hist_search_mode;
    std::string hist_word;
  };

  struct _GtkCompletionLineClass
  {
	GtkEntryClass parent_class;
	/* add your CLASS members here */

    void (* unique)(GtkCompletionLine *cl);
    void (* notunique)(GtkCompletionLine *cl);
    void (* incomplete)(GtkCompletionLine *cl);
    void (* runwithterm)(GtkCompletionLine *cl);
    void (* search_mode)(GtkCompletionLine *cl);
  };

  guint gtk_completion_line_get_type(void);
  GtkWidget *gtk_completion_line_new();

}

#endif /* __GTKCOMPLETIONLINE_H__ */
