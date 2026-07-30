# 🚀 proj

> A lightweight CLI tool for generating **ready-to-build C projects**.

**proj** is a personal utility written in **C** that automates the repetitive setup required when starting a new project. Instead of manually creating folders, writing a `Makefile`, adding a `README`, and preparing a `main.c`, you can generate a complete project structure with a single command.

---

## ✨ Features

* 📁 Create project directories automatically
* 📄 Generate `README.md`, `Makefile`, `LICENSE`, and `.gitignore`
* 🧱 Create `src/` and `include/` folders
* ⚡ Generate a **compilable `src/main.c`**
* 🔁 Safe and **idempotent** `init` command
* 📚 Built-in `--help` and `--version` support

---

## 📦 Quick Start

Create a new project:

```bash id="4q6zk8"
proj create hello_world
```

This generates:

```text id="ajv1eo"
hello_world/
├── README.md
├── Makefile
├── LICENSE
├── .gitignore
├── src/
│   └── main.c
└── include/
```

Build and run:

```bash id="9m0wtt"
cd hello_world
make
./app
```

Output:

```text id="a6r7jj"
Hello from hello_world!
```

---

## 🛠️ Commands

### Create a new project

```bash id="f4vw5c"
proj create my_project
```

You can also create projects inside nested directories:

```bash id="9f69iv"
proj create projects/my_project
```

### Initialize an existing directory

```bash id="dzk19m"
cd existing_folder
proj init
```

### Show help

```bash id="5ks2lf"
proj --help
```

### Show version

```bash id="9yx6gi"
proj --version
```

---

## 🧠 How It Works

`proj` uses a **template-based generation system**. Files stored in the `templates/` directory are copied and processed during project creation.

Example template:

```markdown id="9zzj2z"
# {{PROJECT_NAME}}
```

Generated result:

```markdown id="l95m3n"
# my_project
```

This allows project metadata to be injected dynamically into generated files.

---

## 💡 Motivation

I built **proj** because I was repeatedly creating the same boilerplate structure for every new C project. The goal was to have a **fast, minimal, and portable** tool that could bootstrap a clean development environment in seconds.

Beyond being useful in my daily workflow, the project is also an opportunity to explore:

* modular C architecture,
* file and directory manipulation,
* template processing,
* command-line interface design,
* and build automation with **Make**.

---

## 🗺️ Roadmap

### Current

* [x] Create project folders
* [x] Generate basic project files
* [x] Create `src/` and `include/` structure
* [x] Add `create` command
* [x] Add `init` command
* [x] Add `--help` support
* [x] Add version system
* [x] Generate files from templates
* [x] Support nested project paths
* [x] Replace `{{PROJECT_NAME}}` dynamically
* [x] Generate a working `main.c`

### Planned

* [ ] Automatic `git init`
* [ ] Template variables (`{{AUTHOR}}`, `{{DATE}}`, etc.)
* [ ] Support for **C++**
* [ ] Support for **Python**
* [ ] Global installation target (`make install`)
* [ ] Custom user templates

---

## 🏗️ Building proj

Clone the repository and compile it:

```bash id="9a2qto"
git clone https://github.com/your-username/proj.git
cd proj
make
```

Run locally:

```bash id="f3d5pm"
./proj --help
```

---

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

