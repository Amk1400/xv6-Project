# 🐧 xv6 — Extended with Thread Support

## 📌 Overview
This project is a fork of **[MIT’s xv6 (RISC-V)](https://github.com/mit-pdos/xv6-riscv)**, a re-implementation of Unix Version 6 for educational purposes.  
In this customized version, I have extended xv6 with **kernel-managed threads** and related system calls, providing a simple multi-threading environment inside a process.

---

## ✨ Key Changes
- 🧵 **Thread Abstraction**  
  Added `struct thread` and thread states (`THREAD_UNUSED`, `RUNNABLE`, `RUNNING`, `JOINED`, `SLEEPING`).  
  Defined `NTHREAD = 4` threads per process.  

- ⚙️ **Thread Lifecycle Management**  
  Implemented `allocthread`, `freethread`, `exitthread`, `jointhread`, and `sleepthread`.  
  Integrated thread scheduling logic (`thread_schd`) into the process scheduler.  
  Threads receive their own kernel trapframe and user stack.  

- 🖥️ **System Calls**  
  Added new syscalls:  
  - `thread()` → create a new thread.  
  - `jointhread()` → wait for a thread to finish.  
  Exposed via user space with proper syscall numbers.  

- ⏱️ **Scheduler & Sleep**  
  Extended `scheduler()` to pick runnable threads within a process.  
  Modified `sys_sleep()` to suspend only the calling thread (not the entire process).  

- 🐛 **Trap Handling**  
  Adjusted `trap.c`: if a thread causes a fault, only that thread exits (unless critical).  

- 🧪 **User Test Program**  
  Added `user/threadtest.c`: creates multiple threads, runs simple tasks, and demonstrates `jointhread`.  
  Built automatically via `UPROGS`.  

---

## 🚀 Building & Running

### Requirements
- RISC-V toolchain: [riscv-gnu-toolchain](https://github.com/riscv/riscv-gnu-toolchain) (with `newlib`)  
- QEMU compiled for `riscv64-softmmu`  
- Linux/Unix environment with `make`  

### Build
```bash
make clean
make qemu
```

### Run inside xv6
```bash
$ threadtest
```

---

## 📝 Example Output
```
NEW THREAD CREATED 5
NEW THREAD CREATED 6
NEW THREAD CREATED 7
thread: 101
thread: 102
thread: 103
DONE
```

---

## 📚 References
- [xv6-riscv official repo (MIT PDOS)](https://github.com/mit-pdos/xv6-riscv)  
- [MIT 6.S081 / 6.1810 course materials](https://pdos.csail.mit.edu/6.1810/)  

---

## 📜 License
This project is based on xv6, distributed for educational purposes by MIT.  
Please retain original credits when using or modifying this work.  
