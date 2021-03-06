# -*- coding: utf-8 -*-

"""
***************************************************************************
    VariableDistanceBuffer.py
    ---------------------
    Date                 : August 2012
    Copyright            : (C) 2012 by Victor Olaya
    Email                : volayaf at gmail dot com
***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************
"""

__author__ = 'Victor Olaya'
__date__ = 'August 2012'
__copyright__ = '(C) 2012, Victor Olaya'

# This will get replaced with a git SHA1 when you do a git archive

__revision__ = '$Format:%H$'

import os

from qgis.PyQt.QtGui import QIcon

from qgis.core import (QgsWkbTypes,
                       QgsFeatureSink,
                       QgsProcessingUtils)

from processing.algs.qgis.QgisAlgorithm import QgisAlgorithm
from processing.core.parameters import ParameterVector
from processing.core.parameters import ParameterBoolean
from processing.core.parameters import ParameterNumber
from processing.core.parameters import ParameterTableField
from processing.core.outputs import OutputVector
from . import Buffer as buff
from processing.tools import dataobjects

pluginPath = os.path.split(os.path.split(os.path.dirname(__file__))[0])[0]


class VariableDistanceBuffer(QgisAlgorithm):

    INPUT = 'INPUT'
    OUTPUT = 'OUTPUT'
    FIELD = 'FIELD'
    SEGMENTS = 'SEGMENTS'
    DISSOLVE = 'DISSOLVE'

    def icon(self):
        return QIcon(os.path.join(pluginPath, 'images', 'ftools', 'buffer.png'))

    def group(self):
        return self.tr('Vector geometry tools')

    def __init__(self):
        super().__init__()
        self.addParameter(ParameterVector(self.INPUT,
                                          self.tr('Input layer')))
        self.addParameter(ParameterTableField(self.FIELD,
                                              self.tr('Distance field'), self.INPUT))
        self.addParameter(ParameterNumber(self.SEGMENTS,
                                          self.tr('Segments'), 1, default=5))
        self.addParameter(ParameterBoolean(self.DISSOLVE,
                                           self.tr('Dissolve result'), False))

        self.addOutput(OutputVector(self.OUTPUT, self.tr('Buffer'), datatype=[dataobjects.TYPE_VECTOR_POLYGON]))

    def name(self):
        return 'variabledistancebuffer'

    def displayName(self):
        return self.tr('Variable distance buffer')

    def processAlgorithm(self, parameters, context, feedback):
        layer = QgsProcessingUtils.mapLayerFromString(self.getParameterValue(self.INPUT), context)
        dissolve = self.getParameterValue(self.DISSOLVE)
        field = self.getParameterValue(self.FIELD)
        segments = int(self.getParameterValue(self.SEGMENTS))

        writer = self.getOutputFromName(self.OUTPUT).getVectorWriter(layer.fields(), QgsWkbTypes.Polygon,
                                                                     layer.crs(), context)

        buff.buffering(feedback, context, writer, 0, field, True, layer, dissolve, segments)
