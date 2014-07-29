/* 
 * File:   AStarPropertyType.h
 * Author: lolski
 *
 * Created on December 11, 2012, 3:09 PM
 */

#ifndef ASTARPROPERTYTYPE_H
#define	ASTARPROPERTYTYPE_H

#include <boost/graph/adjacency_list.hpp>

typedef std::map<VertexId, size_t> IndexMap;
typedef std::map<EdgeId, size_t> WeightMap;
typedef std::map<VertexId, VertexId> PredecessorMap;

#endif	/* ASTARPROPERTYTYPE_H */

