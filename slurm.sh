#!/bin/bash
#SBATCH --time=2:00:00
# running on owens
#SBATCH --nodes=1 --ntasks=28
#SBATCH --job-name=5441_lab2
# account for CSE 5441 Au'21
#SBATCH --account=PAS2065
# export PGM=lab2_halll2586_hall2586
export PGM=main

echo job started at `date`
echo on compute node `cat $PBS_NODEFILE`

cd $SLURM_SUBMIT_DIR
# /users/PAS1211/osu1053/CSE_5441/transform_library_mtx
# cp data/PCS_data_test1 data/PCS_data_t00100 data/PCS_data_t00100A data/PCS_data_t00100B data/PCS_data_t00100C data/PCS_data_t00100D data/PCS_data_t00100E data/PCS_data_t01000 data/PCS_data_t05000 data/PCS_data_t10000 data/PCS_data_t20000 $TMPDIR
# cd $TMPDIR

echo job started at `date` >>current.err
echo at `date` >>current.err 
time $SLURM_SUBMIT_DIR/${PGM} <PCS_data_test1  >>current.out 2>current.err
echo job ended at `date` >>current.err

export SAVEDIR=${SLURM_SUBMIT_DIR}'/tests/data_test.'${SLURM_JOBID}
mkdir ${SAVEDIR}
mv current.out ${SAVEDIR}
mv current.err ${SAVEDIR}