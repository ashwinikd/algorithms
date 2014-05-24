/**
 * @file stats.h
 * @author Ashwini Dhekane<ashwini@ashwinidhekane.com>
 * @date 24 May 2014
 *
 * Functions for stats calculation.
 */

#ifndef __AKD_ALGO_STATS_H__
#define __AKD_ALGO_STATS_H__

/**
 * stat_min - find the minimum key in an array.
 */
int stat_min(int * input, int size);

/**
 * stat_max - find the maximum key in an array.
 */
int stat_max(int *input, int size);

/**
 * stat_ith_min - find ith order statistic of the given
 * array.
 */
int stat_ith_min(int *input, int size, int i);

/**
 * _stat_ith_min - finds ith order statistic of the given
 * array. This partitions the input array and finds the
 * ith minimum key by calling itself recursively.
 */
int _stat_ith_min(int *input, int p, int r, int i);

#endif
