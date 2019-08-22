# gr-quantum
GNU Radio Blocks for Quantum Firmware.

message

## Installation

First you need to install the dependencies (see below).

After this, gr-quantum must be installed as any other GNU Radio out-of-tree
module. The producedure usually boils down to doing the following:

```bash
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig
```

Finally, you need to compile the hierarchical flowgraphs include in
gr-quantum (see below).

## Dependencies

gr-quantum requires GNU Radio version 3.7.3.0 or new.
An older version may be used, but note the following:

  * 

Required dependencies:

  * [swig](http://www.swig.org/)

The following GNUradio out-of-tree modules are only required for the decoder of
one particular satellite. You may install only the ones you're interested in.

  * [gr-aausat](https://github.com/daniestevez/gr-aausat) AAUSAT-4 decoder and


## Hierarchichal flowgraphs

Some of the decoders use hierarchichal flowgraphs. These are placed in the
folder `apps/hierarchical`. The hierarchical flowgraphs must be compiled and
installed before using any of the flowgraphs which include them.

To compile and install the hierarchical flowgraphs, the script
`compile_hierarchical.sh` in the root folder can be used.

## Usage
### ゲート系
#### 1量子ビットのゲート
- X ビット反転演算
- Y 位相反転演算
- Z 位相・ビット反転演算
- H アダマール演算
- S Pai/2位相シフト演算
- T Pai/4位相シフト演算

#### 2量子ビットのゲート
- CNOT 制御NOTゲート
- RNOT NOTゲート
- NULL NOT junction point

#### 特殊なゲート
- readout演算子
 - readoutを実施する。実質の観測用ゲート
- 初期化演算子
 - 量子ビットの状態を初期化する。
- wait演算子
 - ナノ秒数waitする


### 観測系（measurement）
- 標準規定測定
 - 観測後の確率表示（Constellation Measurement）
- ブロッホ測定
 - 量子ビットの断層撮影表示（Bloch Measurement）
- 量子シミュレータ・観測器（Qubit Detector）
 - コンパイラのほうに処理結果を返すもの
 - 値を表示するもの


### 操作系(controller)
- 量子ファームウェア実行エンジンソース（Quantum Coprocessor）
 - スクリプトを実行して、波形を出力する
- initializerブロック
 -定数などのセットアップをするブロック
 -量子番号を渡す。CNOTがどこから来たか？がわからなくなるため。そのため、IDは変更不可能とする。
 -シミュレートモード（時間倍率などを変更）
- 量子シミュレータ・実行器（Qubit Simulator）
 - 内部的には接続されていて、状態を両方で保持する。入出力を多数にする方法で多量子ビットを表す。
- 同期
 - 2量子ビット以上利用するときに同期を行う
