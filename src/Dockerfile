# Step 1: GNU Compiler Collection Minimal Docker Official Image
# Available at https://github.com/docker-library/gcc
FROM gcc:latest

# Step 2: Set Build Directory
WORKDIR /usr/src/image-build-tasks

# Step 3: Package Update
RUN apt update 

# Step 4: Package Installation
RUN apt install nano

# Step 5: GSL: GNU Scientific Library Installation 
# Available at https://www.gnu.org/software/gsl/#downloading
RUN wget https://gnu.c3sl.ufpr.br/ftp/gsl/gsl-2.7.tar.gz \
    && tar -xvzf gsl-2.7.tar.gz \
    && cd gsl-2.7 \
    && ./configure \
    && make \
    && make install \
    && cd ..

# Step 6: GLOBES: General Long Baseline Experiment Simulator Library Installation 
# Available at https://www.mpi-hd.mpg.de/personalhomes/globes/download.html
RUN wget https://www.mpi-hd.mpg.de/personalhomes/globes/download/globes-3.2.18.tar.gz \
    && tar -xvzf globes-3.2.18.tar.gz \
    && cd globes-3.2.18 \
    && ./configure \
    && make \
    && make install \
    && cd ..

# Step 7: Install Conda (Mini) To Get CERN ROOT
# Available at https://docs.anaconda.com/free/miniconda/index.html#latest-miniconda-installer-links
RUN mkdir -p ~/miniconda3 \
    && wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh \
    && bash ~/miniconda3/miniconda.sh -b -u -p ~/miniconda3 \
    && ~/miniconda3/bin/conda init bash \
    && ~/miniconda3/bin/conda init zsh \
    && rm -rf ~/miniconda3/miniconda.sh

# Step 8: Install CERN ROOT Via Conda Package Manager
# Instructions at https://root.cern/install/#conda
SHELL ["/bin/bash", "--login" , "-c"]
RUN conda config --set channel_priority strict && \
    conda config --set auto_activate_base false && \ 
    conda create -c conda-forge --name main root -y && \
    conda activate main

# Step 9: Index New Shared Libraries (GSL/GLOBES)
RUN ldconfig

# Step 10: Clear Downloaded Files
RUN cd /usr/src/ && rm -rf image-build-tasks

# Step 11: Set Work Directory
WORKDIR /usr/src/user

# Step 12: Copy Test Files
COPY . /usr/src/user

# Step 13: Download DUNE Files (Experiment Simulation Configurations Used in DUNE CDR)
# Available at https://arxiv.org/abs/2103.04797 => https://arxiv.org/src/2103.04797v2/anc
RUN mkdir dune \
    && cd dune \
    && wget https://arxiv.org/src/2103.04797v2 -O dune.tar \
    && tar -xvzf dune.tar \
    && rm dune.tar \
    && cd ..