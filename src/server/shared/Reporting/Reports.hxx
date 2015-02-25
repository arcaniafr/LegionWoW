#ifndef REPORTS_HXX
# define REPORTS_HXX

namespace MS
{
    namespace Reporting
    {
        enum ReportOpcodes
        {
            AccountCreation = 0,
            BattlegroundInstanciation = 1,
            RealmPopulation = 2,
            BossKilled = 3,
            LauncherDownloading = 4,
            FirstTimeConnexion = 5,
            UpdateDiff = 6,
            AuthChooseRealm = 7,
            IndexWatcher = 8,
            BattlegroundDealDamageWatcher = 9,
        };

        /// Craft a 'AccountCreation' report.
        /// @p_Arg0 : AccountId (expect int64)
        /// @p_Arg1 : Referer (expect text)
        /// @p_Arg2 : IpToCountry (expect text)
        /// @p_Arg3 : MailAddress (expect text)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::AccountCreation>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 4, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "0";
            l_Node["AccountId"] = std::to_string(std::get<0>(l_DeveloppedArgs));
            l_Node["Referer"] = std::get<1>(l_DeveloppedArgs);
            l_Node["IpToCountry"] = std::get<2>(l_DeveloppedArgs);
            l_Node["MailAddress"] = std::get<3>(l_DeveloppedArgs);

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'BattlegroundInstanciation' report.
        /// @p_Arg0 : BattlegroundType (expect int32)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::BattlegroundInstanciation>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 1, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "1";
            l_Node["BattlegroundType"] = std::to_string(std::get<0>(l_DeveloppedArgs));

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'RealmPopulation' report.
        /// @p_Arg0 : RealmName (expect text)
        /// @p_Arg1 : Population (expect int32)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::RealmPopulation>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 2, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "2";
            l_Node["RealmName"] = std::get<0>(l_DeveloppedArgs);
            l_Node["Population"] = std::to_string(std::get<1>(l_DeveloppedArgs));

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'BossKilled' report.
        /// @p_Arg0 : BossName (expect text)
        /// @p_Arg1 : NbKillers (expect int32)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::BossKilled>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 2, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "3";
            l_Node["BossName"] = std::get<0>(l_DeveloppedArgs);
            l_Node["NbKillers"] = std::to_string(std::get<1>(l_DeveloppedArgs));

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'LauncherDownloading' report.
        /// @p_Arg0 : AccountId (expect int64)
        /// @p_Arg1 : Referer (expect text)
        /// @p_Arg2 : IpToCountry (expect text)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::LauncherDownloading>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 3, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "4";
            l_Node["AccountId"] = std::to_string(std::get<0>(l_DeveloppedArgs));
            l_Node["Referer"] = std::get<1>(l_DeveloppedArgs);
            l_Node["IpToCountry"] = std::get<2>(l_DeveloppedArgs);

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'FirstTimeConnexion' report.
        /// @p_Arg0 : AccountId (expect int64)
        /// @p_Arg1 : Race (expect int32)
        /// @p_Arg2 : Classe (expect int32)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::FirstTimeConnexion>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 3, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "5";
            l_Node["AccountId"] = std::to_string(std::get<0>(l_DeveloppedArgs));
            l_Node["Race"] = std::to_string(std::get<1>(l_DeveloppedArgs));
            l_Node["Classe"] = std::to_string(std::get<2>(l_DeveloppedArgs));

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'UpdateDiff' report.
        /// @p_Arg0 : Realm (expect text)
        /// @p_Arg1 : UpdateDiff (expect int32)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::UpdateDiff>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 2, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "6";
            l_Node["Realm"] = std::get<0>(l_DeveloppedArgs);
            l_Node["UpdateDiff"] = std::to_string(std::get<1>(l_DeveloppedArgs));

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'AuthChooseRealm' report.
        /// @p_Arg0 : AccountId (expect int64)
        /// @p_Arg1 : Realm (expect text)
        /// @p_Arg2 : ClientPlatform (expect text)
        /// @p_Arg3 : IpToCountry (expect text)
        /// @p_Arg4 : ClientLang (expect text)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::AuthChooseRealm>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 5, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "7";
            l_Node["AccountId"] = std::to_string(std::get<0>(l_DeveloppedArgs));
            l_Node["Realm"] = std::get<1>(l_DeveloppedArgs);
            l_Node["ClientPlatform"] = std::get<2>(l_DeveloppedArgs);
            l_Node["IpToCountry"] = std::get<3>(l_DeveloppedArgs);
            l_Node["ClientLang"] = std::get<4>(l_DeveloppedArgs);

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'IndexWatcher' report.
        /// @p_Arg0 : Referer (expect text)
        /// @p_Arg1 : IpToCountry (expect text)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::IndexWatcher>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 2, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "8";
            l_Node["Referer"] = std::get<0>(l_DeveloppedArgs);
            l_Node["IpToCountry"] = std::get<1>(l_DeveloppedArgs);

            return l_Node.Serialize<std::ostringstream>();
        }

        /// Craft a 'BattlegroundDealDamageWatcher' report.
        /// @p_Arg0 : Guid (expect int64)
        /// @p_Arg1 : Realm (expect text)
        /// @p_Arg2 : SpellId (expect int32)
        /// @p_Arg3 : Damage (expect int32)
        /// @p_Arg4 : Classe (expect int8)
        /// @p_Arg5 : Race (expect int8)
        /// @p_Arg6 : Specialization (expect text)
        template<>
        template<typename... Args>
        std::string MakeReport<ReportOpcodes::BattlegroundDealDamageWatcher>::Craft(Args... p_Args)
        {
            static_assert(sizeof... (p_Args) == 7, "The number of arguments given is not the one expected.");
            auto&& l_DeveloppedArgs = std::forward_as_tuple(p_Args...);

            EasyJSon::Node<std::string> l_Node;
            l_Node["Opcode"] = "9";
            l_Node["Guid"] = std::to_string(std::get<0>(l_DeveloppedArgs));
            l_Node["Realm"] = std::get<1>(l_DeveloppedArgs);
            l_Node["SpellId"] = std::to_string(std::get<2>(l_DeveloppedArgs));
            l_Node["Damage"] = std::to_string(std::get<3>(l_DeveloppedArgs));
            l_Node["Classe"] = std::to_string(std::get<4>(l_DeveloppedArgs));
            l_Node["Race"] = std::to_string(std::get<5>(l_DeveloppedArgs));
            l_Node["Specialization"] = std::get<6>(l_DeveloppedArgs);

            return l_Node.Serialize<std::ostringstream>();
        }
    }
}
#endif /// !REPORTS_HXX
