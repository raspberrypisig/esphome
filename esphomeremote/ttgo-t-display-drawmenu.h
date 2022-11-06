#pragma once
#include "esphome.h"

int maxItems() {
  int maxItems = ((id(my_display).get_height() - id(header_height)) / (id(medium_font_size) + id(margin_size))) - 1;
  return maxItems;
}


int scrollMenuPosition(int index) {
  int scrollTop = 0;
  if (index - maxItems() > scrollTop) {
    scrollTop = index - maxItems();
    // menu down
  } else if (index - scrollTop < 0) {
    scrollTop = index;
    // menu up
  }
  return scrollTop;
}

Color primaryTextColor() {
  if(id(dark_mode)) {
    return id(my_white);
  } else {
    return id(my_black);
  }
}

Color secondaryTextColor() {
  if(id(dark_mode)) {
    return id(my_white);
  } else {
    return id(my_white);
  }
}

void drawTitle(int menuState, int i, std::string title, int yPos, bool buttonSpace=false) {
  int xPos = buttonSpace ? id(small_font_size) + id(margin_size) * 2 : id(margin_size);
  int textYPos = yPos + (id(margin_size) / 4);
  if (menuState == i) {
    id(my_display).filled_rectangle(0, yPos, id(my_display).get_width(), id(medium_font_size) + id(margin_size), id(color_accent_primary));
    id(my_display).printf(xPos, textYPos, & id(medium_font), secondaryTextColor(), TextAlign::TOP_LEFT, "%s", title.c_str());
  } else {
    id(my_display).printf(xPos, textYPos, & id(medium_font), primaryTextColor(), TextAlign::TOP_LEFT, "%s", title.c_str());
  }
}

void drawMenu(esphome::template_::TemplateSelect *menuTitles) {
  int activeMenuTitleCount = menuTitles->size();
  
  if(activeMenuTitleCount == 0 ) {
    return;
  }
  
  int scrollTop = scrollMenuPosition(id(menuIndex));
  for (int i = scrollTop; i < menuTitles->size(); i++) {
    int yPos = ((i - scrollTop) * (id(medium_font_size) + id(margin_size))) + id(header_height);
    drawTitle(id(menuIndex), i, menuTitles->at(i).value(), yPos);
  }
}
