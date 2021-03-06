#pragma once
/* 
 * This file is part of the RebbleOS distribution.
 *   (https://github.com/pebble-dev)
 * Copyright (c) 2017 Barry Carter <barry.carter@gmail.com>.
 * 
 * RebbleOS is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as   
 * published by the Free Software Foundation, version 3.
 *
 * RebbleOS is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "librebble.h"
#include "point.h"
#include "rect.h"
#include "size.h"
#include "animation.h"
#include "click_config.h"

struct ScrollLayer;

typedef void (*ScrollLayerCallback)(struct ScrollLayer *scroll_layer, void *context);
typedef struct ScrollLayerCallbacks
{
    ClickConfigProvider click_config_provider;
    ScrollLayerCallback content_offset_changed_handler;
} ScrollLayerCallbacks;

typedef struct ScrollLayer
{
    Layer *layer;
    Layer *content_sublayer;
    Layer *shadow_sublayer;
    PropertyAnimation *animation;
    ScrollLayerCallbacks callbacks;
    void *context;
} ScrollLayer;



void scroll_layer_add_child(ScrollLayer *scroll_layer, Layer *child);
void scroll_layer_set_click_config_onto_window(ScrollLayer *scroll_layer, struct Window *window);
void scroll_layer_set_callbacks(ScrollLayer *scroll_layer, ScrollLayerCallbacks callbacks);
void scroll_layer_set_context(ScrollLayer *scroll_layer, void *context);
void scroll_layer_set_content_offset(ScrollLayer *scroll_layer, GPoint offset, bool animated);
GPoint scroll_layer_get_content_offset(ScrollLayer *scroll_layer);
void scroll_layer_set_content_size(ScrollLayer *scroll_layer, GSize size);
GSize scroll_layer_get_content_size(const ScrollLayer *scroll_layer);
void scroll_layer_set_frame(ScrollLayer *scroll_layer, GRect frame);
void scroll_layer_scroll_up_click_handler(ClickRecognizerRef recognizer, void *context);
void scroll_layer_scroll_down_click_handler(ClickRecognizerRef recognizer, void *context);
void scroll_layer_set_shadow_hidden(ScrollLayer *scroll_layer, bool hidden);
bool scroll_layer_get_shadow_hidden(const ScrollLayer *scroll_layer);
void scroll_layer_set_paging(ScrollLayer *scroll_layer, bool paging_enabled);
bool scroll_layer_get_paging(ScrollLayer *scroll_layer);
ContentIndicator *scroll_layer_get_content_indicator(ScrollLayer *scroll_layer);
ContentIndicator *content_indicator_create(void);
void content_indicator_destroy(ContentIndicator *content_indicator);
bool content_indicator_configure_direction(ContentIndicator *content_indicator, ContentIndicatorDirection direction, const ContentIndicatorConfig *config);
bool content_indicator_get_content_available(ContentIndicator *content_indicator, ContentIndicatorDirection direction);
void content_indicator_set_content_available(ContentIndicator *content_indicator, ContentIndicatorDirection direction, bool available);
