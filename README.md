# Posit vs Float: Accurate Small-Value Matrix Operations

This project demonstrates numerical precision differences between:

- **IEEE 754 floats** using [Eigen](https://eigen.tuxfamily.org), a popular C++ linear algebra library.
- **Posit32 numbers** using [SoftPosit](https://github.com/Posit-Foundation/soft-posit-cpp).

We highlight how `posit32` outperforms `float` in operations involving extremely small values where IEEE floats typically suffer from underflow and loss of precision.

---

## 🎯 Project Context

This work is part of the application for Linux Foundation Mentorship Program project:

> **Hardware Abstraction Layer Transitional Library for Software to Hardware Posits for RISC-V – Part II**

The goal is to explore the integration of posits in software applications that heavily rely on floating-point arithmetic, as a transitional step toward hardware support.

---

## 💡 Why Posits for Eigen?

[Eigen](https://eigen.tuxfamily.org) Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.

Using posits instead of IEEE floats in Eigen-based applications can:

- Reduce underflow and overflow in small or large value ranges
- Provide higher accuracy with fewer bits
- Improve numerical stability in deep matrix computations

This makes posits promising for **embedded systems** and **scientific computing** where precision and performance are critical.

---

## 🔧 Build Instructions

### 🖥️ Environment
This project was developed and tested on Linux OS running on an x86 PC. The build scripts and dependencies assume a Linux-based x86 desktop or laptop.


### 🔹 Requirements

- `soft-posit-cpp/`: C++ wrapper around SoftPosit (built)
- `eigen/`: Header-only Eigen library
- `src/posit_vs_float.cpp`: demo source file

Place both `soft-posit-cpp/` and `eigen/` folders in the same root directory as `src/`.

### 🔹 Build

```bash
to build:
make        # or make all

to run the demo
make demo
```
Note: The output binary is stored in the out/ directory.

## 📈 Demo Output
```cmd
Initializing two 2x2 matrices with very small values:
  small1 = 1.000000e-10
  small2 = 1.000000e-30
  One matrix uses IEEE float (Eigen::MatrixXf), the other uses posit32.

[Float Matrix]:
1.0000000134e-10 1.0000000032e-30
1.0000000032e-30 1.0000000134e-10

[Posit32 Matrix]:
1.0000000827e-10 9.8607613153e-31 
9.8607613153e-31 1.0000000827e-10 

[Float Result - Multiplication]:
1.0000000490e-20 0.0000000000e+00
0.0000000000e+00 1.0000000490e-20

[Posit32 Result - Multiplication]:
9.9989592445e-21 7.5231638453e-37 
7.5231638453e-37 9.9989592445e-21 
```

### ✅ Key Insight
Notice how floats underflow to zero, while posit32 retains useful precision even at very small scales.

This behavior confirms that posit arithmetic is more robust in numerical edge cases — especially valuable in scientific and embedded computations.


## 📁 Project Structure

```text
posit-vs-float/
├── eigen/                  # Eigen library (header-only)
├── soft-posit-cpp/         # soft posits library
├── src/
│   └── posit_vs_float.cpp  # demo source
├── out/                    # Output binaries
├── Makefile
└── README.md
```


## Acknowledgements

Linux Foundation Mentorship Program

SoftPosit

Eigen Library

## 📬 Contact
Mohammed Thabet
mohammed.1.alagamy@gmail.com