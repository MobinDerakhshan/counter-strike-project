//
// Created by mobin on 30/09/23.
//

#include "Configuration.h"

Configuration *Configuration::configuration1 = NULL;

Configuration::Configuration() {}

Configuration *Configuration::get_instance() {
  if (configuration1 == NULL) {
      configuration1 = new Configuration();
  }
  return configuration1;
}

void Configuration::clear() {
    delete configuration1;
}
