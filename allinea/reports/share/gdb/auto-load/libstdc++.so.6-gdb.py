# -*- coding: utf-8 -*-
# -*- python -*-
# Copyright (C) 2009 Free Software Foundation, Inc.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import sys
import gdb
import os
import os.path

pythondir = os.path.dirname (__file__) + '/../python'

# Update module path.

if not pythondir in sys.path:
    sys.path.insert(0, pythondir)

# Load the pretty-printers.
from libstdcxx.v6.printers import register_libstdcxx_printers
register_libstdcxx_printers (gdb.current_objfile ())

# Boost is not part of libstdc++ but it's a template library and doesn't have
# necessarily its own shared library.
from boost.v1_40.printers import register_boost_printers
register_boost_printers(gdb.current_objfile ())
