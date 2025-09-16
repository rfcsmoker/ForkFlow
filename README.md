
# ForkFlow: A Decentralized Reality-Branching Sandbox

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Language: C++23](https://img.shields.io/badge/Language-C%2B%2B23-blue.svg)
![Framework: LuaJIT](https://img.shields.io/badge/Framework-LuaJIT-green.svg)

ForkFlow is a decentralized reality simulation sandbox with branching capabilities, combining the depth of Dwarf Fortress with the programmability of Screeps. The game world evolves on Git-like principles, where every change is a commit, and players can create and merge alternative history branches in a fully P2P network.

## 🌟 Key Features

- **Decentralized Branching Reality**: Fork the world, experiment, and attempt to merge your changes back into the main branch. World history is a decentralized acyclic commit graph.
- **P2P Architecture**: The future version will operate on a fully peer-to-peer network where each player is a node storing and synchronizing the universe state.
- **Programmable Agents**: Control "avatars" by programming their AI in ForkScript (a custom Lua framework). They possess memory and act autonomously.
- **Deterministic Simulation**: The game core uses a special ContinuumScript language to describe world changes, ensuring determinism and clean merging in a distributed system.
- **Emergent Gameplay**: Complex scenarios emerge naturally from interactions between dozens of agents, players, and reality branches.

## 🛠 Technology Stack

- **Core**: C++23
- **Networking**: Boost.Asio (with gradual transition to pure P2P)
- **Scripting**: LuaJIT
- **Graphics/Sound/Input**: SDL3
- **Cryptography**: OpenSSL (for delta signing and P2P authentication)
- **Serialization**: FlatBuffers/Protobuf (for efficient delta transmission)

## 🚧 Project Status

The project is at a very early stage of active development. Current work focuses on core architecture, delta systems, and virtual machine implementation. The current version uses a client-server model as a stepping stone toward a full P2P architecture.

## 📂 Project Structure

<details>
<summary><strong>Развернуть структуру проекта</strong></summary>
<pre>
forkflow/
├── 📄 CMakeLists.txt
├── 📂 cmake/
│   ├── 📄 FindLuaJIT.cmake
│   ├── 📄 FindSDL3.cmake
│   └── 📄 ...
├── 📄 conanfile.txt
├── 📂 thirdparty/
├── 📂 include/
│   └── 📂 forkflow/
│       ├── 📂 engine/
│       ├── 📂 vm/
│       ├── 📂 network/
│       └── 📂 ...
├── 📂 src/
│   ├── 📄 CMakeLists.txt
│   ├── 📂 engine/
│   │   ├── 📄 CMakeLists.txt
│   │   ├── 📂 include/
│   │   └── 📂 src/
│   ├── 📂 vm/
│   │   ├── 📄 CMakeLists.txt
│   │   ├── 📂 include/
│   │   └── 📂 src/
│   ├── 📂 network/
│   │   ├── 📄 CMakeLists.txt
│   │   ├── 📂 include/
│   │   └── 📂 src/
│   └── 📂 ...
├── 📂 scripts/
│   ├── 📄 CMakeLists.txt
│   └── 📂 api/
├── 📂 apps/
│   ├── 📄 CMakeLists.txt
│   ├── 📂 server/
│   │   ├── 📄 CMakeLists.txt
│   │   └── 📂 src/
│   └── 📂 client/
│       ├── 📄 CMakeLists.txt
│       └── 📂 src/
├── 📂 tests/
│   ├── 📄 CMakeLists.txt
│   ├── 📂 unit/
│   └── 📂 integration/
├── 📂 docs/
│   ├── 📄 CMakeLists.txt
│   └── 📂 ...
└── 📂 build/
</pre>
</details>

## 🤝 How to Contribute

The project is looking for enthusiasts willing to help with development! Particularly needed:

- C++ developers with experience in multithreading and P2P networks
- Lua experts to help develop the ForkScript API
- Distributed systems and cryptography specialists
- Game designers to help refine branching and merging mechanics

Please be sure to read our Contributing Guidelines and Code of Conduct before participating.

## 📜 License

This project is licensed under the MIT License. See the LICENSE file for details.

*Inspired by Dwarf Fortress, Screeps, Git, BitTorrent, and the concept of a multiverse.*
