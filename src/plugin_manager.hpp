//
// Created by think on 2026/6/3.
//

#pragma once

#include <string>
#include <vector>

#include "plugin_base.hpp"
#include "plugin_metadata.hpp"

class PluginManager {
 private:
  struct LoadedPluginInfo {
    PluginMetadata metadata;
    void* handler;
    PluginBase* instance = nullptr;
    PluginCreateFunc create_func = nullptr;
    PluginDestroyFunc destroy_func = nullptr;
    PluginBase::State state = PluginBase::State::Unloaded;
    PluginBase::Type type = PluginBase::Type::Unknown;
  };

 public:
  explicit PluginManager(const std::string& plugin_dir);
  ~PluginManager();

  // 禁止拷贝
  PluginManager(const PluginManager&) = delete;
  PluginManager& operator=(const PluginManager&) = delete;

  // 元数据扫描
  std::vector<PluginMetadata> ScanAvailablePlugins();
  PluginMetadata GetPluginMetadata(const std::string& name) const;

  // 插件生命周期
  bool LoadPlugin(const std::string& name);
  bool UnloadPlugin(const std::string& name);

  // 批量操作
  bool LoadAll();
  bool StartAll();
  bool StopAll();

  // 查询
  std::vector<std::string> GetLoadedPlugins() const;
  PluginBase::State GetPluginState(const std::string& name) const;
  PluginBase* GetPlugin(const std::string& name);
  PluginBase::Type GetPluginType(const std::string& name) const;

 private:
  std::string plugin_dir_;
  std::map<std::string, LoadedPluginInfo> loaded_plugins_;
};
