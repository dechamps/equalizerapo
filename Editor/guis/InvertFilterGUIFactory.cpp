/*
    This file is part of EqualizerAPO, a system-wide equalizer.
	Copyright (C) 2016  Etienne Dechamps

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "InvertFilterGUI.h"
#include <filters/InvertFilterFactory.h>
#include "InvertFilterGUIFactory.h"

QList<FilterTemplate> InvertFilterGUIFactory::createFilterTemplates()
{
	QList<FilterTemplate> list;
	list.append(FilterTemplate(tr("Invert (Reverse polarity)"), "Invert:", QStringList(tr("Basic filters"))));
	return list;
}

IFilterGUI* InvertFilterGUIFactory::createFilterGUI(QString& command, QString& parameters)
{
	InvertFilterGUI* result = NULL;

	if (command == "Invert")
	{
		InvertFilterFactory factory;
		std::vector<IFilter*> filters = factory.createFilter(L"", command.toStdWString(), parameters.toStdWString());
		if (!filters.empty())
		{
			result = new InvertFilterGUI();
		}

		for (IFilter* f : filters)
		{
			f->~IFilter();
			MemoryHelper::free(f);
		}
	}

	return result;
}
