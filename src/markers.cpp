/*! \file
 * \brief Markers
 * \author OC
 * \date 20100222
 */

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>

#include "markers.h"
KMarkers::KMarkers() {}

KMarkers::~KMarkers()
{
	for (auto marker : m_markers)
	{
		marker = nullptr;
	}
}

bool KMarkers::Add(std::shared_ptr<KMarker> marker)
{
	m_markers.push_back(marker);
	return true;
}

bool KMarkers::Remove(std::shared_ptr<KMarker> marker)
{
	auto found = std::find(m_markers.begin(), m_markers.end(), marker);
	if (found != m_markers.end())
	{
		m_markers.erase(found);
		return true;
	}
	return false;
}

std::shared_ptr<KMarker> KMarkers::GetMarker(size_t index)
{
	if (index < m_markers.size())
	{
		return m_markers[index];
	}
	return nullptr;
}

std::shared_ptr<KMarker> KMarkers::GetMarker(std::string marker_name)
{
	for (auto it = m_markers.begin(); it != m_markers.end(); it++)
	{
		if ((*it)->markerName == marker_name)
		{
			return *it;
		}
	}
	return nullptr;
}

std::shared_ptr<KMarker> KMarkers::GetMarker(int32_t x, int32_t y)
{
	for (auto it = m_markers.begin(); it != m_markers.end(); it++)
	{
		if ((*it)->x == x && (*it)->y == y)
		{
			return *it;
		}
	}
	return nullptr;
}

KMarker Marker;
