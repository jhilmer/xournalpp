#include "LineStyle.h"

#include <cstring>  // for memcpy
#include <vector>   // for vector

#include <glib.h>  // for g_free, g_malloc

#include "util/serializing/ObjectInputStream.h"   // for ObjectInputStream
#include "util/serializing/ObjectOutputStream.h"  // for ObjectOutputStream


LineStyle::LineStyle() = default;

LineStyle::~LineStyle() = default;

auto LineStyle::operator==(const LineStyle& rhs) const -> bool {
    return dashes == rhs.dashes;
}

void LineStyle::serialize(ObjectOutputStream& out) const {
    out.writeObject("LineStyle");

    out.writeData(this->dashes);

    out.endObject();
}

void LineStyle::readSerialized(ObjectInputStream& in) {
    in.readObject("LineStyle");

    in.readData(dashes);

    in.endObject();
}

/**
 * Get dash array and count
 *
 * @return true if dashed
 */
auto LineStyle::getDashes() const -> const std::vector<double>& {
    return dashes;
}

/**
 * Set the dash array and count
 *
 * @param dashes Dash data, will be copied
 * @param dashCount Count of entries
 */
// Todo(fabian): memmory use after free
void LineStyle::setDashes(std::vector<double>&& dashes) {
    this->dashes = std::move(dashes);
}

/**
 * Get dash array and count
 *
 * @return true if dashed
 */
auto LineStyle::hasDashes() const -> bool { return !dashes.empty(); }
