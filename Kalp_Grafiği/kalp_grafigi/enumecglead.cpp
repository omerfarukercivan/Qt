#include "enumecglead.h"

EnumEcgLeadQmlObject* EnumEcgLead::qmlAttachedProperties(QObject *object) {
    Q_UNUSED(object);

    static EnumEcgLeadQmlObject instance;

    return &instance;
}

QString EnumEcgLead::toString(const EnumEcgLead::EcgLead lead) {
    QString string(QMetaEnum::fromType<EnumEcgLead::EcgLead>().valueToKey(lead));

    if (string.front() == 'A')
        string.front() = 'a';

    return string;
}

QVariantList EnumEcgLeadQmlObject::leads() const {
    const auto& metaEnum = QMetaEnum::fromType<EnumEcgLead::EcgLead>();
    const int keyCount = metaEnum.keyCount();
    QVariantList leads;
    leads.reserve(keyCount);

    for (int i = 0; i < keyCount; ++i)
        leads.append(metaEnum.value(i));

    return leads;
}
