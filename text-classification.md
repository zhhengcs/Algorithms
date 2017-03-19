# Text catagorization via deep learning methods

# 1.Baseline:
## 1.1 Supervised algorithm(mainly):
### 1.1.1 SVM/Naive Bayes
* word2vec/n-gram svm
* [Bigram NB-SVM](http://aclweb.org/anthology/P/P12/P12-2018.pdf)
### 1.1.2 CNN
* [*word2vec/non-static/multi-cannal CNN](http://www.aclweb.org/anthology/D/D14/D14-1181.pdf)
* [*one-hot CNN](http://arxiv.org/pdf/1504.01255)
<!-- * [deep CNN](https://arxiv.org/abs/1404.2188) -->
* [*Dynamic CNN](http://aclweb.org/anthology/P14-1062)
* [TBCNN(tree-based convolution)](http://www.aclweb.org/anthology/D/D15/D15-1279.pdf)
* [Character-level CNN](https://arxiv.org/pdf/1509.01626.pdf)
* Modeling-CNN
* CNN-Ana
* MV-CNN(Multichannel variable-size convolution)

### 1.1.3 RNN
* [deep RNN](http://papers.nips.cc/paper/5551-deep-recursive-neural-networks-for-compositionality-in-language.pdf)
* [stack RNN](https://arxiv.org/pdf/1312.6026.pdf)

### 1.1.4 LSTM
* [*one-hot/w2v LSTM](http://jmlr.org/proceedings/papers/v48/johnson16.pdf)
* [*BiLSTM](https://arxiv.org/pdf/1508.01991v1.pdf)
* [Gated RNN](http://www.aclweb.org/website/anthology/D/D15/D15-1167.pdf)
* [Depth-gated RNN](https://arxiv.org/pdf/1508.03790v2.pdf)
* [TBLSTM(tree based)](http://aclweb.org/anthology/P/P15/P15-1150.pdf)
* [*Sequence autoencoders-LSTM/recurrent language models-LSTM](https://arxiv.org/pdf/1511.01432.pdf)
    LSTMs are initialized with a sequence autoencoder, The objective is to reconstruct the input sequence itself
* [RCNN(Recurrent convolutional neural networks)](http://www.aaai.org/ocs/index.php/AAAI/AAAI15/paper/viewFile/9745/9552)
    BiRNN to capture the contextual information,maxpooling
* [*Conv-GRNN and LSTM-GRNN :](Conv-GRNN and LSTM-GRNN)
---a CNN or LSTM provides a sentence vector, and then a gated recurrent neural network (GRNN) combinesthe sentence vectors from a document level vector representation for classification.
* LSTMN
* Multi-Task

### 1.1.5 ReNN
* [RNTN(递归神经张量网络)](http://www.aclweb.org/anthology/D/D13/D13-1170.pdf)
* [DRNN](http://papers.nips.cc/paper/5551-deep-recursive-neural-networks-for-compositionality-in-language.pdf)
* [*MV-RNN(Matrix-Vector)](https://www-nlp.stanford.edu/pubs/SocherHuvalManningNg_EMNLP2012.pdf)
* [Recursive deep model](http://aclweb.org/anthology/D/D13/D13-1170.pdf)

## 1.2 Semi-supervised algorithms
* [semi-supervised CNN](http://arxiv.org/pdf/1504.01255)
* [semi-supervised LSTM](http://jmlr.org/proceedings/papers/v48/johnson16.pdf)
* [Semi-Supervised Recursive Autoencoders(RAE)](http://www.anthology.aclweb.org/D/D11/D11-1014.pdf)
* [*Semi-supervised sequential Variational AutoEncoder (SSVAE)](http://arxiv.org/pdf/1603.02514)
<!-- * Recursive AutoEncoders with pre-trainedword(RAE) -->

## 1.3 Attention based model
* [*attention CNN](http://isca-speech.org/archive/Interspeech_2016/pdfs/0354.PDF)
* [*attention LSTM](http://www.aclweb.org/old_anthology/D/D16/D16-1058.pdf)
* [Hierarchical Attention Networks](https://www.cs.cmu.edu/~diyiy/docs/naacl16.pdf)

## 1.4 other
* [Combinatorial Category Autoencoders]
* [TDNN(时间延迟神经网络)]
* [RBN(受限玻尔兹曼机)](http://www.jmlr.org/papers/volume13/larochelle12a/larochelle12a.pdf)
* [DBN+Active](http://www.aclweb.org/anthology/C10-2173.pdf)
* [Stacked Boltzmann Experts Network](http://www.emnlp2015.org/proceedings/EMNLP/pdf/EMNLP053.pdf)
* http://www0.cs.ucl.ac.uk/staff/w.zhang/papers/lshtc.pdf
* [LSTM讲解](http://www.jianshu.com/p/f3bde26febed)
* [基础讲解](https://mindmodeling.org/cogsci2015/papers/0052/paper0052.pdf)

## 2.Datasets
* English:
    IMDB/20News

* Chinese
    50W article/souhu news 

##  3. Test standard
P, R, F 
