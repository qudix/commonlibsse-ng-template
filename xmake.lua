set_xmakever("2.7.2")

-- project
set_project("template-commonlibsse-ng")
set_version("0.0.0")
set_license("MIT")
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
add_rules("plugin.vsxmake.autoupdate")

-- policies
set_policy("package.requires_lock", true)

-- packages
add_requires("fmt", "spdlog")
add_requires("commonlibsse-ng", { configs = { skyrim_vr = false }})

-- includes
includes("res/package.lua")

-- targets
target("template-plugin")
    add_packages("fmt", "spdlog", "commonlibsse-ng")

    add_rules("@commonlibsse-ng/plugin", {
        name = "template-plugin",
        author = "Qudix",
        description = "SKSE64 plugin template using CommonLibSSE-NG"
    })

    add_files("src/plugin/**.cpp")
    add_includedirs("src/plugin")
    set_pcxxheader("src/plugin/pch.h")

    add_rules("mod.package", {
        ["@{target}-@{target_ver}.zip"] = {
            { "@{target_dir}", "@{target}.dll", "Data/SKSE/Plugins/" },
        },
        ["@{target}-@{target_ver}_pdb.zip"] = {
            { "@{target_dir}", "@{target}.pdb" },
        }
    })
