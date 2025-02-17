/*
    Copyright © 2021 by The qTox Project Contributors

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "util/display.h"

#include <cmath>

QString getHumanReadableSize(uint64_t size)
{
    static const char* suffix[] = {"B", "KiB", "MiB", "GiB", "TiB"};
    int exp = 0;

    if (size > 0) {
        exp = std::min(static_cast<int>(log(size) / log(1024)), static_cast<int>(sizeof(suffix) / sizeof(suffix[0]) - 1));
    }

    return QString().setNum(size / pow(1024, exp), 'f', exp > 1 ? 2 : 0).append(suffix[exp]);
}
