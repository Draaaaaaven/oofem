/*
 *
 *                 #####    #####   ######  ######  ###   ###
 *               ##   ##  ##   ##  ##      ##      ## ### ##
 *              ##   ##  ##   ##  ####    ####    ##  #  ##
 *             ##   ##  ##   ##  ##      ##      ##     ##
 *            ##   ##  ##   ##  ##      ##      ##     ##
 *            #####    #####   ##      ######  ##     ##
 *
 *
 *             OOFEM : Object Oriented Finite Element Code
 *
 *               Copyright (C) 1993 - 2013   Borek Patzak
 *
 *
 *
 *       Czech Technical University, Faculty of Civil Engineering,
 *   Department of Structural Mechanics, 166 29 Prague, Czech Republic
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef ENRICHMENTFRONTLINBRANCHFUNCRADIUS_H_
#define ENRICHMENTFRONTLINBRANCHFUNCRADIUS_H_

#define _IFT_EnrFrontLinearBranchFuncRadius_Name "enrfrontlinearbranchfuncradius"
#define _IFT_EnrFrontLinearBranchFuncRadius_Radius "radius"

#include "oofemcfg.h"
#include <vector>
#include "inputrecord.h"
#include "xfem/enrichmentfronts/enrichmentfront.h"
#include "xfem/tipinfo.h"
#include "xfem/enrichmentfunction.h"

namespace oofem {
class XfemManager;
class DofManager;
class FloatArray;
class InputRecord;
class DynamicInputRecord;
class LinElBranchFunction;

/**
 * EnrFrontLinearBranchFuncRadius
 * @author Erik Svenning
 * @date Feb 14, 2014
 */
class OOFEM_EXPORT EnrFrontLinearBranchFuncRadius : public EnrichmentFront
{
public:
    EnrFrontLinearBranchFuncRadius();
    virtual ~EnrFrontLinearBranchFuncRadius();

    virtual void MarkNodesAsFront(std :: unordered_map< int, int > &ioNodeEnrMarkerMap, XfemManager &ixFemMan, const std :: unordered_map< int, double > &iLevelSetNormalDirMap, const std :: unordered_map< int, double > &iLevelSetTangDirMap, const std :: vector< TipInfo > &iTipInfo);

    virtual int  giveNumEnrichments(const DofManager &iDMan) const;
    virtual int  giveMaxNumEnrichments() const { return 4; }

    // Evaluate the enrichment function and its derivative in front nodes.
    virtual void evaluateEnrFuncAt(std :: vector< double > &oEnrFunc, const FloatArray &iPos, const double &iLevelSet, int iNodeInd) const;
    virtual void evaluateEnrFuncDerivAt(std :: vector< FloatArray > &oEnrFuncDeriv, const FloatArray &iPos, const double &iLevelSet, const FloatArray &iGradLevelSet, int iNodeInd) const;
    virtual void evaluateEnrFuncJumps(std :: vector< double > &oEnrFuncJumps, GaussPoint &iGP, int iNodeInd) const;

    virtual const char *giveClassName() const { return "EnrFrontLinearBranchFuncRadius"; }
    virtual const char *giveInputRecordName() const { return _IFT_EnrFrontLinearBranchFuncRadius_Name; }

    virtual IRResultType initializeFrom(InputRecord *ir);
    virtual void giveInputRecord(DynamicInputRecord &input);

    virtual double giveSupportRadius() const { return mEnrichmentRadius; }

private:
    double mEnrichmentRadius;
    LinElBranchFunction *mpBranchFunc;
};
} // end namespace oofem

#endif /* ENRICHMENTFRONTLINBRANCHFUNCRADIUS_H_ */