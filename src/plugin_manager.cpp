//
// Created by think on 2026/6/3.
//

#include "plugin_manager.hpp"

#include <dlfcn.h>

PluginManager::PluginManager(const std::string& plugin_dir) {

}

PluginManager::~PluginManager() {

}

std::vector<PluginMetadata> PluginManager::ScanAvailablePlugins() {

}

PluginMetadata PluginManager::GetPluginMetadata(const std::string& name) const {
}

bool PluginManager::LoadPlugin(const std::string& name) {

}

bool PluginManager::UnloadPlugin(const std::string& name) {

}

bool PluginManager::LoadAll() {

}

bool PluginManager::StartAll() {

}

bool PluginManager::StopAll() {

}

std::vector<std::string> PluginManager::GetLoadedPlugins() const {}
PluginBase::State PluginManager::GetPluginState(const std::string& name) const {
}
PluginBase* PluginManager::GetPlugin(const std::string& name) {}
PluginBase::Type PluginManager::GetPluginType(const std::string& name) const {}