#pragma once

#include <gtk/gtk.h>
#include <gtk4-layer-shell.h>
#include <gdk/gdkkeysyms.h>
#include <gdk/gdk.h>
#include "config.h"  // For position enum

G_BEGIN_DECLS

#define HYPRMENU_TYPE_WINDOW (hyprmenu_window_get_type())
G_DECLARE_FINAL_TYPE (HyprMenuWindow, hyprmenu_window, HYPRMENU, WINDOW, GtkApplicationWindow)

typedef struct _HyprMenuWindow {
  GtkApplicationWindow parent_instance;
  
  GtkWidget *main_box;
  GtkWidget *search_entry;
  GtkWidget *app_grid;
  GtkWidget *system_buttons_box;
  GtkWidget *recent_apps;
  GtkWidget *pinned_apps;
  
  GtkEventController *key_controller;
  GtkGestureClick *click_gesture;
} HyprMenuWindow;

HyprMenuWindow *hyprmenu_window_new (GtkApplication *app);
void hyprmenu_window_show (HyprMenuWindow *self);

G_END_DECLS 