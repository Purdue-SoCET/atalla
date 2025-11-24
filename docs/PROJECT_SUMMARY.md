# Atalla 0x01 项目总结 - 面试准备文档

## 项目简介 (Project Overview)

**项目名称**: Atalla 0x01 - 学生主导的AI硬件-软件协同设计项目

**所属团队**: Purdue-SoCET (Purdue System-on-Chip Extension Technologies)

**项目目标**: 设计并实现一个完整的AI硬件-软件栈，从RTL级硬件设计到PyTorch集成，打造一个开源、可复现、研究级的AI加速器基础设施。

---

## 面试说辞模板

> "这是我参与的**Atalla AI加速器项目**，我们的目标是设计一个**端到端的AI硬件-软件协同系统**，包括自定义的脉动阵列、矩阵调度器核心、多级缓存和片上临时存储(Scratchpad)。与Google开源的TPU相比，我们的创新点主要体现在以下几个方面..."

---

## 核心设计目标 (Design Goals)

### 1. 全栈设计 (Full-Stack Design)
- **硬件层**: RTL设计 (SystemVerilog)
- **编译器**: 自定义编译器基础设施 (aihw-ppci-compiler)
- **仿真器**: 周期精确模拟器 (atalla-sim)
- **验证**: 形式化验证、功能验证、UVM验证

### 2. 工艺目标
- 当前: MIT Lincoln Lab 90nm
- 计划升级: TSMC 65nm

---

## 核心架构组件 (Core Architecture Components)

### 1. 脉动阵列 (Systolic Array)
**位置**: `rtl/modules/systolic_array/`

**特点**:
- 可参数化的N×N维度 (默认4×4)
- 16-bit数据宽度
- 基于MAC (Multiply-Accumulate) 单元
- 流水线化的权重加载和部分和累加
- 双FIFO结构: 输入FIFO + 部分和FIFO + 输出FIFO

**核心模块**:
- `systolic_array.sv` - 顶层脉动阵列
- `sysarr_MAC.sv` - 乘累加单元
- `sysarr_control_unit.sv` - 控制单元
- `sysarr_FIFO.sv` / `sysarr_OUT_FIFO.sv` - 数据缓冲

### 2. 调度器核心 (Scheduler Core)
**位置**: `rtl/modules/scheduler/`

**特点**:
- 基于RISC-V指令扩展的自定义ISA
- 乱序执行架构 (Out-of-Order Execution)
- 多功能单元并行执行
- Tomasulo算法风格的寄存器重命名

**功能单元类型**:
- **标量ALU**: 基本算术逻辑运算
- **标量Load/Store**: 内存访问
- **分支单元**: 条件跳转、分支预测
- **矩阵Load/Store**: 矩阵数据搬运
- **GEMM单元**: 通用矩阵乘法加速

**核心模块**:
- `scheduler_core.sv` - 调度器核心顶层
- `dispatch.sv` - 指令派发
- `issue.sv` - 指令发射
- `execute.sv` - 执行阶段
- `scoreboard.sv` - 记分板
- `fu_gemm.sv` - GEMM功能单元
- `fu_alu.sv` - ALU功能单元
- `fu_branch_predictor.sv` - 分支预测器

### 3. 自定义ISA扩展
**位置**: `rtl/include/scheduler/isa_types.vh`

**新增指令类型**:
```systemverilog
LD_M  = 7'b1000011  // 矩阵加载
ST_M  = 7'b1010011  // 矩阵存储
GEMM  = 7'b1110011  // 通用矩阵乘法
```

### 4. 片上临时存储 (Scratchpad Memory)
**位置**: `rtl/modules/memory/scratchpad/`

**规格**:
- 默认1MB容量
- 32列 × 16-bit元素
- 2个Scratchpad实例
- 支持SRAM垂直折叠优化

**特点**:
- 前端(Frontend) + 后端(Backend) + 主体(Body) 三段式架构
- 可配置的交叉开关网络
- 支持行/列访问模式
- DRAM接口集成

### 5. 交叉开关网络 (Crossbar Networks)
**位置**: `rtl/modules/common/xbar/`

**支持的网络类型**:
- **Benes网络**: 可重排列非阻塞网络
- **Batcher网络**: 排序网络
- **Naive交叉开关**: 简单全连接

**可配置性**:
- 全流水线 / 组合逻辑 / 自定义折叠
- 支持多种延迟-面积权衡配置

### 6. 缓存系统
**位置**: `rtl/modules/memory/caches/`

**组件**:
- `icache.sv` - 指令缓存
- `dcache.sv` - 数据缓存  
- `lockup_free_cache.sv` - 无锁缓存
- `cache_mshr_buffer.sv` - Miss状态处理寄存器

---

## 与Google TPU的对比创新点 (Innovations vs Google TPU)

### 1. 可编程调度器核心
- **TPU v1**: 固定功能的矩阵运算单元，依赖主机CPU调度
- **Atalla**: 集成RISC-V兼容的可编程调度器核心，支持自定义ISA扩展，可在片上进行细粒度任务调度

### 2. 灵活的内存层次
- **TPU**: 统一缓冲区(Unified Buffer)设计
- **Atalla**: 多Scratchpad + 多级缓存 + 可配置交叉开关网络，支持更灵活的数据流模式

### 3. 开放的硬件-软件协同设计
- **TPU**: 闭源硬件，仅开放API接口
- **Atalla**: 完全开源的RTL设计、编译器、仿真器，支持端到端研究

### 4. 可扩展的脉动阵列
- **TPU v1**: 固定256×256脉动阵列
- **Atalla**: 参数化设计，可配置阵列维度、数据宽度、流水线深度

### 5. 分支预测与投机执行
- **TPU**: 确定性执行模型，无分支预测
- **Atalla**: 集成BTB(Branch Target Buffer)和BPT(Branch Prediction Table)，支持投机执行以提高控制密集型工作负载性能

### 6. 完整的验证生态
- **形式化验证**: `/tb/formal/`
- **单元测试**: `/tb/unit/`
- **UVM验证**: 基于UVM 1.2标准

---

## 技术栈 (Technology Stack)

### 硬件设计
- **语言**: SystemVerilog
- **综合工具**: Cadence Genus
- **物理设计**: Cadence Innovus
- **仿真工具**: QuestaSim / ModelSim

### 软件工具
- **编译器**: 自定义PPCI编译器
- **仿真器**: 周期精确C++仿真器
- **验证**: UVM 1.2

---

## 设计参数示例 (Sample Design Parameters)

### 脉动阵列
```systemverilog
parameter N = 4        // 4×4阵列维度
parameter WIDTH = 16   // 16-bit数据宽度
parameter MUL_LEN = 2  // 乘法流水线级数
parameter ADD_LEN = 3  // 加法流水线级数
```

### Scratchpad
```systemverilog
parameter SCPAD_SIZE_BYTES = 1*1024*1024  // 1MB
parameter NUM_COLS = 32                    // 32列
parameter ELEM_BITS = 16                   // 16-bit元素
parameter NUM_SCPADS = 2                   // 2个实例
```

---

## 综合报告数据 (Synthesis Results)

### Batcher排序网络 (参考)
- **工艺**: 基于MIT LL 90nm
- **时钟周期**: 3000ps (333MHz)
- **关键路径余量**: 1580.8ps
- **Cell面积**: 209,874.867 μm²
- **功耗**: ~98mW

---

## 项目亮点总结 (Key Highlights)

1. **学术研究导向**: 完全开源，适合发表论文和进行架构探索
2. **全栈可控**: 从RTL到编译器完全自主设计
3. **工业级验证**: 采用UVM标准化验证方法学
4. **可扩展架构**: 参数化设计支持多种配置
5. **协作开发**: 多人团队协作，包含版本控制和CI/CD

---

## 常见面试问题准备

### Q: 为什么选择脉动阵列架构？
**A**: 脉动阵列天然适合矩阵乘法运算，数据流动规则，可以最大化数据复用，减少片上存储器带宽压力。每个MAC单元只需要与相邻单元通信，布线简单且可扩展。

### Q: 如何解决矩阵计算的数据搬运瓶颈？
**A**: 我们采用多级存储层次：片外DRAM → Scratchpad → 脉动阵列输入FIFO，并使用可配置的交叉开关网络支持灵活的数据重排，减少不必要的数据搬运。

### Q: 为什么需要自定义ISA扩展？
**A**: 标准RISC-V ISA缺乏对矩阵运算的原生支持，我们添加了LD_M/ST_M/GEMM指令，允许调度器核心直接控制矩阵单元，减少软件开销。

### Q: 与商业AI加速器相比，学术项目的价值在哪？
**A**: 完全开源允许深入研究每个设计决策，适合探索新的架构思想。我们可以灵活修改任何组件，不受商业限制，这对于学术研究和教育都有重要价值。

---

*文档生成时间: 2025年11月*
