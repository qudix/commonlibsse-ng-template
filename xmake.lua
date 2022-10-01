set_xmakever("2.7.1")

-- project
set_project("template-commonlibsse-ng")
set_version("0.0.0")
set_languages("c++20")
set_optimize("faster")
set_warnings("allextra", "error")

-- allowed
set_allowedarchs("x64")
set_allowedmodes("debug", "releasedbg")

-- default
set_defaultarchs("x64")
set_defaultmode("releasedbg")

-- rules
add_rules("mode.debug", "mode.releasedbg")

-- policies
set_policy("build.optimization.lto", true)
set_policy("package.requires_lock", true)

-- packages
add_requires("fmt", "spdlog")
add_requires("commonlibsse-ng", { configs = { skyrim_vr = false }})

includes("res/commonlib.lua")

target("plugin")
    add_packages("fmt", "spdlog", "commonlibsse-ng")

    add_rules("commonlibsse.plugin", {
        name = "template-commonlibsse-ng",
        author = "Qudix",
        license = "MIT",
        sources = {
            files = { "src/plugin/**.cpp" },
            headers = { "src/plugin/**.h" },
            include = "src/plugin",
            pch = "src/plugin/pch.h"
        }
    })

    add_rules("commonlibsse.plugin.package", {
        packages = {
            {
                name = "@{plugin}-@{plugin_ver}.zip",
                files = {
                    { "@{target_dir}", "*.dll", "Data/SKSE/Plugins/" },
                }
            },
            {
                name = "@{plugin}-@{plugin_ver}_pdb.zip",
                files = {
                    { "@{target_dir}", "*.pdb" },
                }
            }
        }
    })
