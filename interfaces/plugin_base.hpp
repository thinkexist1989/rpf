//
// Created by think on 6/2/26.
//

#pragma once

#include <string>

#ifdef _WIN32
#ifdef RPF_EXPORTS
#define PLUGIN_API __declspec(dllexport)
#else
#define PLUGIN_API __declspec(dllimport)
#endif
#else
#define PLUGIN_API __attribute__((visibility("default")))
#endif

class PluginBase {
 public:
  enum class State { Unloaded, Loaded, Initialized, Error };

  enum class Type { Hardware, Planner, Controller, Kinematics, Dynamics, Unknown };

  virtual ~PluginBase() = default;

  // 生命周期
  virtual bool Initialize() = 0;  // TODO: 初始化应该要删掉，因为不用的插件初始化的依赖注入不一样
  virtual void Unload() = 0;

  // 状态查询
  [[nodiscard]] virtual State GetState() const = 0;
  [[nodiscard]] virtual std::string GetName() const = 0;
  [[nodiscard]] virtual std::string GetVersion() const = 0;
};

using PluginCreateFunc = PluginBase* (*)();
using PluginDestroyFunc = void (*)(PluginBase*);

// 宏定义，用于简化插件导出
#define RPF_PLUGIN_EXPORT(PluginClass)                                  \
  (                                                                     \
      extern "C" PLUGIN_API PluginBase *                                \
      create_plugin() {                                                 \
        return new PluginClass();                                       \
      } extern "C" PLUGIN_API void destroy_plugin(PluginBase* plugin) { \
        delete plugin;                                                  \
      })
