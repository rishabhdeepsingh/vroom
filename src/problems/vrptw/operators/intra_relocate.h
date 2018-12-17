#ifndef VRPTW_INTRA_RELOCATE_H
#define VRPTW_INTRA_RELOCATE_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "problems/cvrp/operators/intra_relocate.h"
#include "structures/vroom/tw_route.h"

class vrptwIntraRelocate : public CVRPIntraRelocate {
private:
  TWRoute& _tw_s_route;

  std::vector<Index> _moved_jobs;
  const Index _first_rank;
  const Index _last_rank;

public:
  vrptwIntraRelocate(const Input& input,
                     const SolutionState& sol_state,
                     TWRoute& tw_s_route,
                     Index s_vehicle,
                     Index s_rank,
                     Index t_rank); // relocate rank *after* removal.

  virtual bool is_valid() override;

  virtual void apply() override;

  virtual std::vector<Index> addition_candidates() const override;
};

#endif
